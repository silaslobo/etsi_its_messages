/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_VehicleBreakdownSubCauseCode_H_
#define	_asn_VehicleBreakdownSubCauseCode_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum asn_VehicleBreakdownSubCauseCode {
	asn_VehicleBreakdownSubCauseCode_unavailable	= 0,
	asn_VehicleBreakdownSubCauseCode_lackOfFuel	= 1,
	asn_VehicleBreakdownSubCauseCode_lackOfBatteryPower	= 2,
	asn_VehicleBreakdownSubCauseCode_engineProblem	= 3,
	asn_VehicleBreakdownSubCauseCode_transmissionProblem	= 4,
	asn_VehicleBreakdownSubCauseCode_engineCoolingProblem	= 5,
	asn_VehicleBreakdownSubCauseCode_brakingSystemProblem	= 6,
	asn_VehicleBreakdownSubCauseCode_steeringProblem	= 7,
	asn_VehicleBreakdownSubCauseCode_tyrePuncture	= 8,
	asn_VehicleBreakdownSubCauseCode_tyrePressureProblem	= 9
} e_asn_VehicleBreakdownSubCauseCode;

/* asn_VehicleBreakdownSubCauseCode */
typedef long	 asn_VehicleBreakdownSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_VehicleBreakdownSubCauseCode;
asn_struct_free_f asn_VehicleBreakdownSubCauseCode_free;
asn_struct_print_f asn_VehicleBreakdownSubCauseCode_print;
asn_constr_check_f asn_VehicleBreakdownSubCauseCode_constraint;
per_type_decoder_f asn_VehicleBreakdownSubCauseCode_decode_uper;
per_type_encoder_f asn_VehicleBreakdownSubCauseCode_encode_uper;
per_type_decoder_f asn_VehicleBreakdownSubCauseCode_decode_aper;
per_type_encoder_f asn_VehicleBreakdownSubCauseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _asn_VehicleBreakdownSubCauseCode_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
