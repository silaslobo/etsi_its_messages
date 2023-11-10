/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
 * 	found in "/input/ISO-TS-19091-addgrp-C-2018.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_EmissionType_H_
#define	_EmissionType_H_


#include <etsi_its_spatem_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_spatem_coding/NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum EmissionType {
	EmissionType_euro1	= 0,
	EmissionType_euro2	= 1,
	EmissionType_euro3	= 2,
	EmissionType_euro4	= 3,
	EmissionType_euro5	= 4,
	EmissionType_euro6	= 5
	/*
	 * Enumeration is extensible
	 */
} e_EmissionType;

/* EmissionType */
typedef long	 EmissionType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_EmissionType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_EmissionType;
extern const asn_INTEGER_specifics_t asn_SPC_EmissionType_specs_1;
asn_struct_free_f EmissionType_free;
asn_struct_print_f EmissionType_print;
asn_constr_check_f EmissionType_constraint;
ber_type_decoder_f EmissionType_decode_ber;
der_type_encoder_f EmissionType_encode_der;
xer_type_decoder_f EmissionType_decode_xer;
xer_type_encoder_f EmissionType_encode_xer;
oer_type_decoder_f EmissionType_decode_oer;
oer_type_encoder_f EmissionType_encode_oer;
per_type_decoder_f EmissionType_decode_uper;
per_type_encoder_f EmissionType_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _EmissionType_H_ */
#include <etsi_its_spatem_coding/asn_internal.h>
