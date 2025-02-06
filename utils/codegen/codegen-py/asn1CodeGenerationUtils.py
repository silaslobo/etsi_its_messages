# ==============================================================================
# MIT License
#
# Copyright (c) 2023-2024 Institute for Automotive Engineering (ika), RWTH Aachen University
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# ==============================================================================

import logging
import re
import sys
from typing import Dict, List, Optional, Tuple

import asn1tools
import numpy as np


# color logging levels in output
logging.addLevelName(logging.WARNING, "\033[1;33m%s\033[1;0m" % logging.getLevelName(logging.WARNING))
logging.addLevelName(logging.ERROR, "\033[1;31m%s\033[1;0m" % logging.getLevelName(logging.ERROR))


AUTO_GENERATE_COMMAND = "python3 " + " ".join(sys.argv)


ASN1_PRIMITIVES_2_ROS = {
    "BOOLEAN": "bool",
    "INTEGER": "int64",
    "IA5String": "string",
    "UTF8String": "string",
    "BIT STRING": "uint8[]",
    "OCTET STRING": "uint8[]",
    "NumericString": "string",
    "VisibleString": "string",
}


def validRosType(s: str) -> str:
    """Converts a string to make it a valid ROS message type.

    Regex: ^[A-Z][A-Za-z0-9]*$

    Args:
        s (str): A-Message-Type

    Returns:
        str: A_Message_Type
    """

    ss = s

    # keep built-in types as they are
    if ss.rstrip("[]") in ["bool", "byte", "char", "float32", "float64", "int8", "uint8", "int16", "uint16", "int32", "uint32", "int64", "uint64", "string", "wstring"]:
        return ss

    # remove - and _
    ss = ss.replace("-", "").replace("_", "")

    # make sure first character is a letter
    if not ss[0].isalpha():
        ss = "A" + ss

    # capitalize first letter
    ss = ss[0].upper() + ss[1:]

    return ss


def validRosField(s: str, is_const: bool = False) -> str:
    """Converts a string to make it a valid ROS message field name.

    Regex for field: ^(?!.*__)(?!.*_$)[a-z][a-z0-9_]*$
    Regex for constant: ^[A-Z]([A-Z0-9_]?[A-Z0-9]+)*$

    Args:
        s (str): A-Ros-Message-Field
        is_const (bool): whether the field is a constant

    Returns:
        str: a_ros_message_field or A_ROS_MESSAGE_FIELD
    """

    ss = s

    # add _ before upper-case letters following lower-case letters or numbers
    ss = re.sub("(?<=[a-z0-9])([A-Z])", r"_\1", ss)

    # add _ before upper-case letters before lower-case letters
    ss = re.sub("([A-Z])(?=[a-z])", r"_\1", ss)

    # remove leading _, replace - with _, remove double _
    ss = ss.lstrip("_").replace("-", "_").replace("__", "_")

    # to upper, if const
    ss = ss.upper() if is_const else ss.lower()

    # avoid C/C++ keywords
    if ss == "class":
        ss = "cls"
    if ss == "long":
        ss = "lon"

    return ss


def validRosTypeHeader(s: str) -> str:
    """Converts a string to make it a valid ROS message header file name.

    Args:
        s (str): A-Message-Type

    Returns:
        str: a_message_type
    """

    return validRosField(validRosType(s))


def validCFieldAsGenByAsn1c(s: str) -> str:
    """Converts a string to make it a valid C message field name as generated by asn1c.

    Args:
        s (str): e.g., "cla-ss"

    Returns:
        str: e.g., "Class"
    """

    ss = s

    # replace - with _
    ss = ss.replace("-", "_")

    # avoid C/C++ keywords
    if ss == "class":
        ss = "Class"
    if ss == "long":
        ss = "Long"

    return ss


def noSpace(s: str) -> str:
    """Replaces any spaces in a string with underscores.

    Args:
        s (str): my string

    Returns:
        str: my_string
    """

    return s.replace(" ", "_")


def simplestRosIntegerType(min_value: int, max_value: int) -> str:
    """Returns the simplest/smallest ROS integer type covering the specified range.

    Args:
        min_value (int): minimum value
        max_value (int): maximum value

    Raises:
        ValueError: if specified range is not supported by any ROS integer type

    Returns:
        str: simplest/smallest ROS integer type, e.g., `uint32`
    """

    if min_value >= np.iinfo(np.uint8).min and max_value <= np.iinfo(np.uint8).max:
        return "uint8"
    elif min_value >= np.iinfo(np.uint16).min and max_value <= np.iinfo(np.uint16).max:
        return "uint16"
    elif min_value >= np.iinfo(np.uint32).min and max_value <= np.iinfo(np.uint32).max:
        return "uint32"
    elif min_value >= np.iinfo(np.uint64).min and max_value <= np.iinfo(np.uint64).max:
        return "uint64"
    elif min_value >= np.iinfo(np.int8).min and max_value <= np.iinfo(np.int8).max:
        return "int8"
    elif min_value >= np.iinfo(np.int16).min and max_value <= np.iinfo(np.int16).max:
        return "int16"
    elif min_value >= np.iinfo(np.int32).min and max_value <= np.iinfo(np.int32).max:
        return "int32"
    elif min_value >= np.iinfo(np.int64).min and max_value <= np.iinfo(np.int64).max:
        return "int64"
    else:
        return ValueError(f"No ROS integer type supports range [{min_value}, {max_value}]")


def parseAsn1Files(files: List[str]) -> Tuple[Dict, Dict[str, str]]:
    """Parses ASN1 files.

    Args:
        files (List[str]): filepaths

    Returns:
        Tuple[Dict, Dict[str, str]]: parsed type information by document, raw string definition by type
    """

    asn1_raw = {}
    for file in files:
        with open(file) as f:
            lines = f.readlines()
        raw_def = None
        for line_idx, line in enumerate(lines):
            if "::=" in line:
                comment_lines = []
                for rline in reversed(lines[:line_idx]):
                    if rline.strip().endswith("*/"):
                        comment_lines.append(rline)
                    elif len(comment_lines) > 0:
                        comment_lines.append(rline)
                    if rline.strip().startswith("/**"):
                        comment_lines = reversed(comment_lines)
                        break
                if line.rstrip().endswith("{"):
                    type = line.split("::=")[0].split("{")[0].strip().split()[0]
                    raw_def = ""
                elif len(line.split("::=")) == 2:
                    type = line.split("::=")[0].strip().split()[0]
                    if "}" in line or not ("{" in line or "}" in line):
                        raw_def = line
                        asn1_raw[type] = "".join(comment_lines) + raw_def
                        raw_def = None
                    else:
                        raw_def = ""
            if raw_def is not None:
                raw_def += line
                # TODO: improve this condition
                if "}" in line and not "}," in line and not "} |" in line and not "} )" in line and not "})" in line and not ("::=" in line and line.rstrip().endswith("{")):
                    asn1_raw[type] = "".join(comment_lines) + raw_def
                    raw_def = None

    asn1_docs = asn1tools.parse_files(files)

    return asn1_docs, asn1_raw


def docForAsn1Type(asn1_type: str, asn1_docs: Dict) -> Optional[str]:
    """Finds the ASN1 document where a specific type is defined.

    Args:
        asn1_type (str): type name
        asn1_docs (Dict): parsed type information by document (from `parseAsn1Files`)

    Returns:
        Optional[str]: document name where type is defined, `None` if not found
    """

    for doc, asn1 in asn1_docs.items():
        if asn1_type in asn1["types"]:
            return doc

    return None


def extractAsn1TypesFromDocs(asn1_docs: Dict) -> Dict[str, Dict]:
    """Extracts all parsed ASN1 type information from multiple ASN1 documents.

    Args:
        asn1_docs (Dict): type information by document

    Raises:
        ValueError: if a type is found in multiple documents

    Returns:
        Dict[str, Dict]: type information by type
    """

    asn1_types = {}
    for doc, asn1 in asn1_docs.items():
        for type in asn1["types"]:
            if type not in asn1_types:
                asn1_types[type] = asn1["types"][type]
            else:
                raise ValueError(f"Type '{type}' from '{doc}' is a duplicate")

    return asn1_types

def extractAsn1ValuesFromDocs(asn1_docs: Dict) -> Dict[str, Dict]:
    """Extracts all parsed ASN1 value information from multiple ASN1 documents.

    Args:
        asn1_docs (Dict): type information by document

    Raises:
        ValueError: if a type is found in multiple documents

    Returns:
        Dict[str, Dict]: value information by name
    """

    asn1_values = {}
    for doc, asn1 in asn1_docs.items():
        for value in asn1["values"]:
            if value not in asn1_values:
                asn1_values[value] = asn1["values"][value]
            else:
                raise ValueError(f"Value '{value}' from '{doc}' is a duplicate")

    return asn1_values

def extractAsn1ClassesFromDocs(asn1_docs: Dict) -> Dict[str, Dict]:
    """Extracts all parsed ASN1 class information from multiple ASN1 documents.

    Args:
        asn1_docs (Dict): type information by document

    Raises:
        ValueError: if a class is found in multiple documents

    Returns:
        Dict[str, Dict]: class information by name
    """

    asn1_classes = {}
    for doc, asn1 in asn1_docs.items():
        for class_name in asn1["object-classes"]:
            if class_name not in asn1_classes:
                asn1_classes[class_name] = asn1["object-classes"][class_name]
            else:
                raise ValueError(f"Class '{class_name}' from '{doc}' is a duplicate")

    return asn1_classes

def extractAsn1SetsFromDocs(asn1_docs: Dict) -> Dict[str, Dict]:
    """Extracts all parsed ASN1 set information from multiple ASN1 documents.

    Args:
        asn1_docs (Dict): type information by document

    Raises:
        ValueError: if a set is found in multiple documents

    Returns:
        Dict[str, Dict]: set information by name
    """

    asn1_sets = {}
    for doc, asn1 in asn1_docs.items():
        for set_name in asn1["object-sets"]:
            if set_name not in asn1_sets:
                asn1_sets[set_name] = asn1["object-sets"][set_name]
            else:
                raise ValueError(f"Set '{set_name}' from '{doc}' is a duplicate")

    return asn1_sets

def checkTypeMembersInAsn1(asn1_types: Dict[str, Dict]):
    """Checks if all type information is known and supported.

    This helps to check whether the types of all members of a type are also known.

    Args:
        asn1_types (Dict[str, Dict]): type information by type

    Raises:
        TypeError: if the type of a member is not part of the given types, hence unknown
    """

    known_types = ["SEQUENCE", "SEQUENCE OF", "CHOICE", "ENUMERATED", "NULL", "CPM-CONTAINER-ID-AND-TYPE.&id", "CPM-CONTAINER-ID-AND-TYPE.&Type"]
    known_types += list(asn1_types.keys())
    known_types += list(ASN1_PRIMITIVES_2_ROS.keys())

    # loop all types
    for asn1_type_name, asn1_type_info in asn1_types.items():

        # loop all members in type
        for member in asn1_type_info.get("members", []):

            if member is None:
                continue

            if isinstance(member, list):
                for sub_member in member:
                    if sub_member["type"] not in known_types:
                        raise TypeError(
                            f"Type '{sub_member['type']}' of member '{sub_member['name']}' "
                            f"in '{asn1_type_name}' is undefined")
                continue

            if "components-of" in member:
                member["type"] = member["components-of"]

            # check if type is known
            if member["type"] not in known_types:
                if ".&" in member["type"]: # class type is currently just handled for CPM
                    logging.warning(
                        f"Type '{member['type']}' of member '{member['name']}' "
                        f"in '{asn1_type_name}' seems to relate to a 'CLASS' type, not "
                        f"yet supported")
                else:
                    raise TypeError(
                        f"Type '{member['type']}' of member '{member['name']}' "
                        f"in '{asn1_type_name}' is undefined")


def asn1TypeToJinjaContext(asn1_type_name: str, asn1_type_info: Dict, asn1_types: Dict[str, Dict], asn1_values: Dict[str, Dict], asn1_sets: Dict[str, Dict], asn1_classes: Dict[str, Dict]) -> Dict:
    """Builds a jinja context containing all type information required to fill the templates / code generation.

    Args:
        asn1_type_name (str): type name
        asn1_type_info (Dict): type information
        asn1_types (Dict[str, Dict]): type information of all types by type
        asn1_values (Dict[str, Dict]): value information of all values by name
        asn1_sets (Dict[str, Dict]): set information of all sets by name
        asn1_classes (Dict[str, Dict]): class information of all classes by name

    Returns:
        Dict: jinja context
    """

    if isinstance(asn1_type_info, list): # list represents the asn1 extension "[[ ]]" notation
        asn1_type_type = "EXTENSION"
    else:
        asn1_type_type = asn1_type_info["type"]

    context = {
        "etsi_type": None,                                              # cam
        "asn1_type_type": noSpace(asn1_type_type),                      # SEQUENCE
        "asn1_type_name": asn1_type_name,                               # CamParameters
        "ros_msg_type": validRosType(asn1_type_name),                   # CamParameters
        "ros2_msg_type_file_name": validRosTypeHeader(asn1_type_name),  # cam_parameters
        "is_primitive": False,
        "members": [],
        "asn1_definition": None,
        "comments": [],
        "auto_generate_command": AUTO_GENERATE_COMMAND,
    }

    # extra information / asn1 fields that are not processed as comments
    if not isinstance(asn1_type_info, list):
        for k, v in asn1_type_info.items():
            if k not in ("type", "element", "members", "name", "named-bits", "named-numbers", "optional", "restricted-to", "size", "values", "default"):
                context["comments"].append(f"{k}: {v}")

    # components-of
    if "components-of" in asn1_type_info:
        member_context = asn1TypeToJinjaContext(asn1_type_name, asn1_types[asn1_type_info["components-of"]], asn1_types, asn1_values, asn1_sets, asn1_classes)
        context["members"].extend(member_context["members"])

    # primitives
    elif asn1_type_type in ASN1_PRIMITIVES_2_ROS:

        # resolve ROS msg type
        ros_type = ASN1_PRIMITIVES_2_ROS[asn1_type_type]
        name = asn1_type_info["name"] if "name" in asn1_type_info else "value"

        # choose simplest possible integer type
        if "restricted-to" in asn1_type_info and asn1_type_type == "INTEGER":
            min_value = asn1_type_info["restricted-to"][0][0]
            max_value = asn1_type_info["restricted-to"][0][1]
            ros_type = simplestRosIntegerType(min_value, max_value)

        # parse member to jinja context
        member_context = {
            "asn1_type_name": asn1_type_type,
            "ros_msg_type": validRosType(ros_type),
            "ros_field_name": validRosField(name),
            "c_field_name": validCFieldAsGenByAsn1c(name),
            "constants": [],
            "is_primitive": True,
            "has_bits_unused": False,
        }

        # add bits_unused field for BIT STRINGs
        if asn1_type_type == "BIT STRING":
            member_context["has_bits_unused"] = True

        # add constants for limits
        if "restricted-to" in asn1_type_info:
            min_value = asn1_type_info["restricted-to"][0][0]
            max_value = asn1_type_info["restricted-to"][0][1]
            min_constant_name = "MIN"
            max_constant_name = "MAX"
            if "name" in asn1_type_info:
                min_constant_name = validRosField(f"{asn1_type_info['name']}_{min_constant_name}", is_const=True)
                max_constant_name = validRosField(f"{asn1_type_info['name']}_{max_constant_name}", is_const=True)
            member_context["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(min_constant_name, is_const=True),
                "ros_value": min_value
            })
            member_context["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(max_constant_name, is_const=True),
                "ros_value": max_value
            })

        # add constants for size limits
        if "size" in asn1_type_info:
            if isinstance(asn1_type_info["size"][0], tuple):
                min_size = asn1_type_info["size"][0][0]
                max_size = asn1_type_info["size"][0][1]
                ros_type = simplestRosIntegerType(min_size, max_size)
                min_size_constant_name = "MIN_SIZE" if asn1_type_type != "BIT STRING" else "MIN_SIZE_BITS"
                max_size_constant_name = "MAX_SIZE" if asn1_type_type != "BIT STRING" else "MAX_SIZE_BITS"
                if "name" in asn1_type_info:
                    min_size_constant_name = validRosField(f"{asn1_type_info['name']}_{min_size_constant_name}", is_const=True)
                    max_size_constant_name = validRosField(f"{asn1_type_info['name']}_{max_size_constant_name}", is_const=True)
                member_context["constants"].append({
                    "ros_msg_type": validRosType(ros_type),
                    "ros_field_name": validRosField(min_size_constant_name, is_const=True),
                    "ros_value": min_size
                })
                member_context["constants"].append({
                    "ros_msg_type": validRosType(ros_type),
                    "ros_field_name": validRosField(max_size_constant_name, is_const=True),
                    "ros_value": max_size
                })
            else:
                size = asn1_type_info["size"][0]
                ros_type = simplestRosIntegerType(size, size)
                size_constant_name = "SIZE" if asn1_type_type != "BIT STRING" else "SIZE_BITS"
                if "name" in asn1_type_info:
                    size_constant_name = validRosField(f"{asn1_type_info['name']}_{size_constant_name}", is_const=True)
                member_context["constants"].append({
                    "ros_msg_type": validRosType(ros_type),
                    "ros_field_name": validRosField(size_constant_name, is_const=True),
                    "ros_value": size
                })

        # add constants for named numbers
        if "named-numbers" in asn1_type_info:
            for k, v in asn1_type_info["named-numbers"].items():
                constant_name = validRosField(k, is_const=True)
                if "name" in asn1_type_info:
                    constant_name = validRosField(f"{asn1_type_info['name']}_{constant_name}", is_const=True)
                member_context["constants"].append({
                    "ros_msg_type": validRosType(ros_type),
                    "ros_field_name": validRosField(constant_name, is_const=True),
                    "ros_value": v
                })

        # add index constants for named bits
        if "named-bits" in asn1_type_info:
            for k, v in asn1_type_info["named-bits"]:
                member_context["constants"].append({
                    "ros_msg_type": "uint8",
                    "ros_field_name": validRosField(f"BIT_INDEX_{k}", is_const=True),
                    "ros_value": v
                })

        context["members"].append(member_context)

    # nested types
    elif asn1_type_type == "SEQUENCE":

        # recursively add all members
        for member in asn1_type_info["members"]:
            if member is None:
                continue
            member_context = asn1TypeToJinjaContext(asn1_type_name, member, asn1_types, asn1_values, asn1_sets, asn1_classes)
            if member_context is None:
                continue
            if "optional" in member:
                member_context["members"][0]["optional"] = True
            if "default" in member:
                asn1_value = {}
                if member["default"] in asn1_values:
                    asn1_value = asn1_values[member["default"]]
                elif "named-numbers" in asn1_types[member["type"]] and member["default"] in asn1_types[member["type"]]["named-numbers"]:
                    asn1_value["value"] = asn1_types[member["type"]]["named-numbers"][member["default"]]
                    asn1_value["type"] = asn1_types[member["type"]]["type"]
                elif asn1_types[member["type"]]["type"] == "ENUMERATED":
                    for default_tuple in asn1_types[member["type"]]["values"]:
                        if default_tuple[0] == member["default"]:
                            asn1_value["value"] = default_tuple[1]
                            asn1_value["type"] = asn1_types[member["type"]]["type"]
                default_value = asn1_value["value"]
                default_name = validRosField(f"{member['name']}_DEFAULT", is_const=True)
                if asn1_value["type"] == 'INTEGER' or asn1_value["type"] == 'ENUMERATED':
                    default_type = simplestRosIntegerType(default_value, default_value)
                else:
                    default_type = ASN1_PRIMITIVES_2_ROS[asn1_value["type"]]
                member_context["members"][0]["default"] = {
                    "ros_msg_type": validRosType(default_type),
                    "ros_field_name": validRosField(default_name, is_const=True),
                    "ros_value": default_value
                }
            context["members"].extend(member_context["members"])

    # type aliases with multiple options
    elif asn1_type_type == "CHOICE":

        # add flag for indicating active option
        name = "choice"
        if "name" in asn1_type_info:
            name = f"{asn1_type_info['name']}_{name}"
        name = validRosField(name)
        context["members"].append({
            "ros_msg_type": "uint8",
            "ros_field_name": validRosField(name),
            "is_choice_var": True
        })

         # disable choice identifier, if identified by another property (e.g., in the case of CLASS)
        if "identified_by" in asn1_type_info:
            name = asn1_type_info["identified_by"]
            context["members"][0]["disabled"] = True

        # recursively add members for all options, incl. constant for flag
        for im, member in enumerate(asn1_type_info["members"]):
            if member is None:
                continue
            member_name = validRosField(f"CHOICE_{member['name']}", is_const=True)
            if "name" in asn1_type_info:
                member_name = validRosField(f"CHOICE_{asn1_type_info['name']}_{member['name']}", is_const=True)
            member_context = asn1TypeToJinjaContext(asn1_type_name, member, asn1_types, asn1_values, asn1_sets, asn1_classes)
            if member_context is None:
                continue
            if len(member_context["members"]) > 0:
                if "name" in asn1_type_info:
                    member_context["members"][0]["choice_name"] = validCFieldAsGenByAsn1c(asn1_type_info["name"])
                    member_context["members"][0]["choice_option_name"] = validCFieldAsGenByAsn1c(member_context["members"][0]["c_field_name"])
                    member_context["members"][0]["ros_field_name"] = validRosField(f"{asn1_type_info['name']}_{member_context['members'][0]['ros_field_name']}")
                    member_context["members"][0]["c_field_name"] = validCFieldAsGenByAsn1c(f"{asn1_type_info['name']}_{member_context['members'][0]['c_field_name']}")
                member_context["members"][0]["is_choice"] = True
                member_context["members"][0]["choice_var_name"] = name
                member_context["members"][0]["constants"] = member_context["members"][0].get("constants", [])
                for c_idx, constant in enumerate(member_context["members"][0]["constants"]):
                    member_context["members"][0]["constants"][c_idx]["ros_field_name"] = validRosField(f"{member_context['members'][0]['ros_field_name']}_{constant['ros_field_name']}", is_const=True)
                # set choice value based on index or asn1 values if identified by another property (e.g., in the case of CLASS)
                choice_value = im
                if "identified_by" in asn1_type_info:
                    asn1_value_name = member_context["asn1_type_type"][0].lower() + member_context["asn1_type_type"][1:]
                    if asn1_value_name in asn1_values:
                        choice_value = asn1_values[asn1_value_name]["value"]
                member_context["members"][0]["constants"].append({
                    "ros_msg_type": "uint8",
                    "ros_field_name": validRosField(member_name, is_const=True),
                    "ros_value": choice_value
                })
            context["members"].extend(member_context["members"])

    # arrays
    elif asn1_type_type == "SEQUENCE OF":

        # add field for array
        array_name = asn1_type_info["name"] if "name" in asn1_type_info else "array"
        array_type = asn1_type_info['element']['type']

        if array_type == "RegionalExtension":
            logging.warning(f"Handling of 'RegionalExtension' in '{asn1_type_name}' not yet supported")
            return None

        member_context = {
            "asn1_type_name": array_type,
            "ros_msg_type": f"{validRosType(array_type)}[]",
            "ros2_msg_type_file_name": f"{validRosTypeHeader(array_type)}",
            "ros_field_name": validRosField(array_name),
            "c_field_name": validCFieldAsGenByAsn1c(array_name),
            "constants": []
        }

        # add constants for size limits
        if "size" in asn1_type_info and isinstance(asn1_type_info["size"][0], tuple):
            min_size = asn1_type_info["size"][0][0]
            max_size = asn1_type_info["size"][0][1]
            ros_type = simplestRosIntegerType(min_size, max_size)
            min_size_constant_name = "MIN_SIZE"
            max_size_constant_name = "MAX_SIZE"
            if "name" in asn1_type_info:
                min_size_constant_name = validRosField(f"{asn1_type_info['name']}_{min_size_constant_name}", is_const=True)
                max_size_constant_name = validRosField(f"{asn1_type_info['name']}_{max_size_constant_name}", is_const=True)
            member_context["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(min_size_constant_name, is_const=True),
                "ros_value": min_size
            })
            member_context["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(max_size_constant_name, is_const=True),
                "ros_value": max_size
            })
        elif "size" in asn1_type_info and isinstance(asn1_type_info["size"][0], int):
            size = asn1_type_info["size"][0]
            ros_type = simplestRosIntegerType(size, size)
            size_constant_name = "SIZE"
            if "name" in asn1_type_info:
                size_constant_name = validRosField(f"{asn1_type_info['name']}_{size_constant_name}", is_const=True)
            member_context["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(size_constant_name, is_const=True),
                "ros_value": size
            })

        context["members"].append(member_context)

    # enums
    elif asn1_type_type == "ENUMERATED":

        # choose simplest possible integer type
        values = [val[1] for val in asn1_type_info["values"] if val is not None]
        min_value = min(values)
        max_value = max(values)
        ros_type = simplestRosIntegerType(min_value, max_value)

        # add field for active value
        member_context = {
            "ros_msg_type": validRosType(ros_type),
            "ros_field_name": "value",
            "constants": [],
        }

        # add constants for all values
        for val in asn1_type_info["values"]:
            if val is None:
                continue
            member_context["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(val[0], is_const=True),
                "ros_value": val[1]
            })

        context["members"].append(member_context)
        
    # list aka extension "[[ ]]"    
    elif asn1_type_type == "EXTENSION":
        for sub_member in asn1_type_info:
            member_context = asn1TypeToJinjaContext(asn1_type_name, sub_member, asn1_types, asn1_values, asn1_sets, asn1_classes)
            member_context["members"][0]["extension_prefix"] = "ext1->"
            if member_context is not None:
                context["members"].extend(member_context["members"])

    # custom types
    elif asn1_type_type in asn1_types:

        if asn1_type_type == "RegionalExtension":
            logging.warning(f"Handling of 'RegionalExtension' in '{asn1_type_name}' not yet supported")
            return None

        name = asn1_type_info["name"] if "name" in asn1_type_info else "value"
        context["members"].append({
            "asn1_type_name": asn1_type_type,
            "ros_msg_type": validRosType(asn1_type_type),
            "ros_field_name": validRosField(name),
            "c_field_name": validCFieldAsGenByAsn1c(name),
            "constants": []
        })
        
        if "optional" in asn1_type_info:
            context["members"][0]["optional"] = True

        # handle size in custom types
        if "size" in asn1_type_info and isinstance(asn1_type_info["size"][0], tuple):
            min_size = asn1_type_info["size"][0][0]
            max_size = asn1_type_info["size"][0][1]
            ros_type = simplestRosIntegerType(min_size, max_size)
            min_size_constant_name = "MIN_SIZE"
            max_size_constant_name = "MAX_SIZE"
            if "name" in asn1_type_info:
                min_size_constant_name = validRosField(f"{asn1_type_info['name']}_{min_size_constant_name}", is_const=True)
                max_size_constant_name = validRosField(f"{asn1_type_info['name']}_{max_size_constant_name}", is_const=True)
            context["members"][0]["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(min_size_constant_name, is_const=True),
                "ros_value": min_size
            })
            context["members"][0]["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(max_size_constant_name, is_const=True),
                "ros_value": max_size
            })
        elif "size" in asn1_type_info and isinstance(asn1_type_info["size"][0], int):
            size = asn1_type_info["size"][0]
            ros_type = simplestRosIntegerType(size, size)
            size_constant_name = "SIZE"
            if "name" in asn1_type_info:
                size_constant_name = validRosField(f"{asn1_type_info['name']}_{size_constant_name}", is_const=True)
            context["members"][0]["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(size_constant_name, is_const=True),
                "ros_value": size
            })

        # add constants for limits (TODO: duplicate with primitives)
        if "restricted-to" in asn1_type_info and isinstance(asn1_type_info["restricted-to"][0], tuple):
            min_value = asn1_type_info["restricted-to"][0][0]
            max_value = asn1_type_info["restricted-to"][0][1]
            ros_type = simplestRosIntegerType(min_value, max_value)
            min_constant_name = "MIN"
            max_constant_name = "MAX"
            if "name" in asn1_type_info:
                min_constant_name = validRosField(f"{asn1_type_info['name']}_{min_constant_name}", is_const=True)
                max_constant_name = validRosField(f"{asn1_type_info['name']}_{max_constant_name}", is_const=True)
            context["members"][0]["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(min_constant_name, is_const=True),
                "ros_value": min_value
            })
            context["members"][0]["constants"].append({
                "ros_msg_type": validRosType(ros_type),
                "ros_field_name": validRosField(max_constant_name, is_const=True),
                "ros_value": max_value
            })

    # class types
    elif ".&" in asn1_type_type and asn1_type_type.split(".")[0] in asn1_classes:
        asn1_class = asn1_classes[asn1_type_type.split(".")[0]]
        for member in asn1_class["members"]:
            if member["name"] == asn1_type_type.split(".")[1]:
                class_member = {
                    "name": asn1_type_info["name"],
                    "type": member["type"]
                }
                if member["type"] not in asn1_types:
                    class_member["type"] = "CHOICE"
                    class_member["members"] = []
                    if type(asn1_type_info["table"]) is list:
                        identifier = asn1_type_info["table"][1][0] # structure known from CPM
                        class_member["identified_by"] = validRosField(identifier) + ".value"
                    for value in asn1_values:
                        for member in asn1_class["members"]:
                            if member["type"] == asn1_values[value]["type"]:
                                class_member["members"].append({
                                    "name": value[0].upper() + value[1:], # make sure type starts with upper case
                                    "type": value[0].upper() + value[1:] # make sure type starts with upper case
                                })
                member_context = asn1TypeToJinjaContext(asn1_type_name, class_member, asn1_types, asn1_values, asn1_sets, asn1_classes)
                context["members"].extend(member_context["members"])

    elif asn1_type_type == "NULL":

        pass

    else:

        logging.warning(f"Cannot handle type '{asn1_type_type}'")

    return context
