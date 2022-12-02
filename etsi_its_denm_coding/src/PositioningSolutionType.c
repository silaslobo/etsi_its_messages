/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#include "PositioningSolutionType.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_PositioningSolutionType_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_PositioningSolutionType_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  5 }	/* (0..5,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_PositioningSolutionType_value2enum_1[] = {
	{ 0,	21,	"noPositioningSolution" },
	{ 1,	5,	"sGNSS" },
	{ 2,	5,	"dGNSS" },
	{ 3,	11,	"sGNSSplusDR" },
	{ 4,	11,	"dGNSSplusDR" },
	{ 5,	2,	"dR" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_PositioningSolutionType_enum2value_1[] = {
	2,	/* dGNSS(2) */
	4,	/* dGNSSplusDR(4) */
	5,	/* dR(5) */
	0,	/* noPositioningSolution(0) */
	1,	/* sGNSS(1) */
	3	/* sGNSSplusDR(3) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_PositioningSolutionType_specs_1 = {
	asn_MAP_PositioningSolutionType_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_PositioningSolutionType_enum2value_1,	/* N => "tag"; sorted by N */
	6,	/* Number of elements in the maps */
	7,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_PositioningSolutionType_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_PositioningSolutionType = {
	"PositioningSolutionType",
	"PositioningSolutionType",
	&asn_OP_NativeEnumerated,
	asn_DEF_PositioningSolutionType_tags_1,
	sizeof(asn_DEF_PositioningSolutionType_tags_1)
		/sizeof(asn_DEF_PositioningSolutionType_tags_1[0]), /* 1 */
	asn_DEF_PositioningSolutionType_tags_1,	/* Same as above */
	sizeof(asn_DEF_PositioningSolutionType_tags_1)
		/sizeof(asn_DEF_PositioningSolutionType_tags_1[0]), /* 1 */
	{ &asn_OER_type_PositioningSolutionType_constr_1, &asn_PER_type_PositioningSolutionType_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_PositioningSolutionType_specs_1	/* Additional specs */
};

