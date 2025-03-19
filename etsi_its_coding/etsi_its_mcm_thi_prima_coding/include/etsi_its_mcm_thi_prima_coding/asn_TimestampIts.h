/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_TimestampIts_H_
#define	_asn_TimestampIts_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/INTEGER.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum asn_TimestampIts {
	asn_TimestampIts_utcStartOf2004	= 0,
	asn_TimestampIts_oneMillisecAfterUTCStartOf2004	= 1
} e_asn_TimestampIts;

/* asn_TimestampIts */
typedef INTEGER_t	 asn_TimestampIts_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_asn_TimestampIts_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_asn_TimestampIts;
asn_struct_free_f asn_TimestampIts_free;
asn_struct_print_f asn_TimestampIts_print;
asn_constr_check_f asn_TimestampIts_constraint;
per_type_decoder_f asn_TimestampIts_decode_uper;
per_type_encoder_f asn_TimestampIts_encode_uper;
per_type_decoder_f asn_TimestampIts_decode_aper;
per_type_encoder_f asn_TimestampIts_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _asn_TimestampIts_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
