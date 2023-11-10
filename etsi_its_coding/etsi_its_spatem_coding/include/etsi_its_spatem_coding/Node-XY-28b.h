/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/input/ISO-TS-19091-addgrp-C-2018.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_Node_XY_28b_H_
#define	_Node_XY_28b_H_


#include <etsi_its_spatem_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_spatem_coding/Offset-B14.h"
#include <etsi_its_spatem_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Node-XY-28b */
typedef struct Node_XY_28b {
	Offset_B14_t	 x;
	Offset_B14_t	 y;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Node_XY_28b_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Node_XY_28b;
extern asn_SEQUENCE_specifics_t asn_SPC_Node_XY_28b_specs_1;
extern asn_TYPE_member_t asn_MBR_Node_XY_28b_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _Node_XY_28b_H_ */
#include <etsi_its_spatem_coding/asn_internal.h>
