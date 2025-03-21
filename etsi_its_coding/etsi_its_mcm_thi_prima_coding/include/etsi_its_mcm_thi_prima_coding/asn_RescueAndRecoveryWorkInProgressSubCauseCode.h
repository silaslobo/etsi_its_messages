/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_RescueAndRecoveryWorkInProgressSubCauseCode_H_
#define	_asn_RescueAndRecoveryWorkInProgressSubCauseCode_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum asn_RescueAndRecoveryWorkInProgressSubCauseCode {
	asn_RescueAndRecoveryWorkInProgressSubCauseCode_unavailable	= 0,
	asn_RescueAndRecoveryWorkInProgressSubCauseCode_emergencyVehicles	= 1,
	asn_RescueAndRecoveryWorkInProgressSubCauseCode_rescueHelicopterLanding	= 2,
	asn_RescueAndRecoveryWorkInProgressSubCauseCode_policeActivityOngoing	= 3,
	asn_RescueAndRecoveryWorkInProgressSubCauseCode_medicalEmergencyOngoing	= 4,
	asn_RescueAndRecoveryWorkInProgressSubCauseCode_childAbductionInProgress	= 5
} e_asn_RescueAndRecoveryWorkInProgressSubCauseCode;

/* asn_RescueAndRecoveryWorkInProgressSubCauseCode */
typedef long	 asn_RescueAndRecoveryWorkInProgressSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_RescueAndRecoveryWorkInProgressSubCauseCode;
asn_struct_free_f asn_RescueAndRecoveryWorkInProgressSubCauseCode_free;
asn_struct_print_f asn_RescueAndRecoveryWorkInProgressSubCauseCode_print;
asn_constr_check_f asn_RescueAndRecoveryWorkInProgressSubCauseCode_constraint;
per_type_decoder_f asn_RescueAndRecoveryWorkInProgressSubCauseCode_decode_uper;
per_type_encoder_f asn_RescueAndRecoveryWorkInProgressSubCauseCode_encode_uper;
per_type_decoder_f asn_RescueAndRecoveryWorkInProgressSubCauseCode_decode_aper;
per_type_encoder_f asn_RescueAndRecoveryWorkInProgressSubCauseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _asn_RescueAndRecoveryWorkInProgressSubCauseCode_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
