/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_PtActivationType_H_
#define	_asn_PtActivationType_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum asn_PtActivationType {
	asn_PtActivationType_undefinedCodingType	= 0,
	asn_PtActivationType_r09_16CodingType	= 1,
	asn_PtActivationType_vdv_50149CodingType	= 2
} e_asn_PtActivationType;

/* asn_PtActivationType */
typedef long	 asn_PtActivationType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_asn_PtActivationType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_asn_PtActivationType;
asn_struct_free_f asn_PtActivationType_free;
asn_struct_print_f asn_PtActivationType_print;
asn_constr_check_f asn_PtActivationType_constraint;
per_type_decoder_f asn_PtActivationType_decode_uper;
per_type_encoder_f asn_PtActivationType_encode_uper;
per_type_decoder_f asn_PtActivationType_decode_aper;
per_type_encoder_f asn_PtActivationType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _asn_PtActivationType_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
