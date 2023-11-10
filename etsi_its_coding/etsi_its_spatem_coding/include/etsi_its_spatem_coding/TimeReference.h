/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
 * 	found in "/input/ISO-TS-19091-addgrp-C-2018.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_TimeReference_H_
#define	_TimeReference_H_


#include <etsi_its_spatem_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_spatem_coding/NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TimeReference {
	TimeReference_oneMilliSec	= 1
} e_TimeReference;

/* TimeReference */
typedef long	 TimeReference_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_TimeReference_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_TimeReference;
asn_struct_free_f TimeReference_free;
asn_struct_print_f TimeReference_print;
asn_constr_check_f TimeReference_constraint;
ber_type_decoder_f TimeReference_decode_ber;
der_type_encoder_f TimeReference_encode_der;
xer_type_decoder_f TimeReference_decode_xer;
xer_type_encoder_f TimeReference_encode_xer;
oer_type_decoder_f TimeReference_decode_oer;
oer_type_encoder_f TimeReference_encode_oer;
per_type_decoder_f TimeReference_decode_uper;
per_type_encoder_f TimeReference_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _TimeReference_H_ */
#include <etsi_its_spatem_coding/asn_internal.h>
