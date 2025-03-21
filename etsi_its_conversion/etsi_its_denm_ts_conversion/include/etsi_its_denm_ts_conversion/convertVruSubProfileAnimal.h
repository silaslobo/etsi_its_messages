/** ============================================================================
MIT License

Copyright (c) 2023-2025 Institute for Automotive Engineering (ika), RWTH Aachen University

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
============================================================================= */

/** Auto-generated by https://github.com/ika-rwth-aachen/etsi_its_messages -----
python3 \
  utils/codegen/codegen-py/asn1ToConversionHeader.py \
  asn1/raw/denm_ts103831/DENM-PDU-Descriptions.asn \
  asn1/patched/denm_ts103831/cdd/ETSI-ITS-CDD.asn \
  -t \
  denm_ts \
  -o \
  etsi_its_conversion/etsi_its_denm_ts_conversion/include/etsi_its_denm_ts_conversion
----------------------------------------------------------------------------- */

/** ASN.1 Definition -----------------------------------------------------------
*
 * This DE indicates the profile of an animal
 * 
 * The value shall be set to:
 * - 0 `unavailable`     - to indicate that the information  is unavailable,
 * - 1 `wild-animal`     - to indicate a animal living in the wildness, 
 * - 2 `farm-animal`     - to indicate an animal beloning to a farm,
 * - 3 `service-animal`  - to indicate an animal that supports a human being.
 * - 4 to 15             - are reserved for future usage. 
 *
 * @category: VRU information
 * @revision: Created in V2.1.1, type changed from ENUMERATED to INTEGER in V2.2.1
 *
VruSubProfileAnimal ::= INTEGER {
    unavailable    (0), 
    wild-animal    (1), 
    farm-animal    (2), 
    service-animal (3)
}(0..15)
----------------------------------------------------------------------------- */

#pragma once

#include <etsi_its_denm_ts_coding/denm_ts_VruSubProfileAnimal.h>
#include <etsi_its_denm_ts_coding/INTEGER.h>
#include <etsi_its_primitives_conversion/convertINTEGER.h>
#ifdef ROS1
#include <etsi_its_denm_ts_msgs/VruSubProfileAnimal.h>
namespace denm_ts_msgs = etsi_its_denm_ts_msgs;
#else
#include <etsi_its_denm_ts_msgs/msg/vru_sub_profile_animal.hpp>
namespace denm_ts_msgs = etsi_its_denm_ts_msgs::msg;
#endif


namespace etsi_its_denm_ts_conversion {

void toRos_VruSubProfileAnimal(const denm_ts_VruSubProfileAnimal_t& in, denm_ts_msgs::VruSubProfileAnimal& out) {
  etsi_its_primitives_conversion::toRos_INTEGER(in, out.value);
}

void toStruct_VruSubProfileAnimal(const denm_ts_msgs::VruSubProfileAnimal& in, denm_ts_VruSubProfileAnimal_t& out) {
  memset(&out, 0, sizeof(denm_ts_VruSubProfileAnimal_t));
  etsi_its_primitives_conversion::toStruct_INTEGER(in.value, out);
}

}
