/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_SteeringWheelAngleValue_H_
#define	_asn_SteeringWheelAngleValue_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum asn_SteeringWheelAngleValue {
	asn_SteeringWheelAngleValue_straight	= 0,
	asn_SteeringWheelAngleValue_onePointFiveDegreesToRight	= -1,
	asn_SteeringWheelAngleValue_onePointFiveDegreesToLeft	= 1,
	asn_SteeringWheelAngleValue_unavailable	= 512
} e_asn_SteeringWheelAngleValue;

/* asn_SteeringWheelAngleValue */
typedef long	 asn_SteeringWheelAngleValue_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_asn_SteeringWheelAngleValue_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_asn_SteeringWheelAngleValue;
asn_struct_free_f asn_SteeringWheelAngleValue_free;
asn_struct_print_f asn_SteeringWheelAngleValue_print;
asn_constr_check_f asn_SteeringWheelAngleValue_constraint;
per_type_decoder_f asn_SteeringWheelAngleValue_decode_uper;
per_type_encoder_f asn_SteeringWheelAngleValue_encode_uper;
per_type_decoder_f asn_SteeringWheelAngleValue_decode_aper;
per_type_encoder_f asn_SteeringWheelAngleValue_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _asn_SteeringWheelAngleValue_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
