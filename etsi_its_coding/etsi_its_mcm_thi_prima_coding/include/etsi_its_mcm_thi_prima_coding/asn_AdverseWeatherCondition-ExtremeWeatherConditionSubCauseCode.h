/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_H_
#define	_asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode {
	asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_unavailable	= 0,
	asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_strongWinds	= 1,
	asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_damagingHail	= 2,
	asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_hurricane	= 3,
	asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_thunderstorm	= 4,
	asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_tornado	= 5,
	asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_blizzard	= 6
} e_asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode;

/* asn_AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode */
typedef long	 asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode;
asn_struct_free_f asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_free;
asn_struct_print_f asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_print;
asn_constr_check_f asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_constraint;
per_type_decoder_f asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_decode_uper;
per_type_encoder_f asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_encode_uper;
per_type_decoder_f asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_decode_aper;
per_type_encoder_f asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _asn_AdverseWeatherCondition_ExtremeWeatherConditionSubCauseCode_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
