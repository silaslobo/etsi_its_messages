/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_CauseCodeType_H_
#define	_asn_CauseCodeType_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum asn_CauseCodeType {
	asn_CauseCodeType_reserved	= 0,
	asn_CauseCodeType_trafficCondition	= 1,
	asn_CauseCodeType_accident	= 2,
	asn_CauseCodeType_roadworks	= 3,
	asn_CauseCodeType_impassability	= 5,
	asn_CauseCodeType_adverseWeatherCondition_Adhesion	= 6,
	asn_CauseCodeType_aquaplannning	= 7,
	asn_CauseCodeType_hazardousLocation_SurfaceCondition	= 9,
	asn_CauseCodeType_hazardousLocation_ObstacleOnTheRoad	= 10,
	asn_CauseCodeType_hazardousLocation_AnimalOnTheRoad	= 11,
	asn_CauseCodeType_humanPresenceOnTheRoad	= 12,
	asn_CauseCodeType_wrongWayDriving	= 14,
	asn_CauseCodeType_rescueAndRecoveryWorkInProgress	= 15,
	asn_CauseCodeType_adverseWeatherCondition_ExtremeWeatherCondition	= 17,
	asn_CauseCodeType_adverseWeatherCondition_Visibility	= 18,
	asn_CauseCodeType_adverseWeatherCondition_Precipitation	= 19,
	asn_CauseCodeType_slowVehicle	= 26,
	asn_CauseCodeType_dangerousEndOfQueue	= 27,
	asn_CauseCodeType_vehicleBreakdown	= 91,
	asn_CauseCodeType_postCrash	= 92,
	asn_CauseCodeType_humanProblem	= 93,
	asn_CauseCodeType_stationaryVehicle	= 94,
	asn_CauseCodeType_emergencyVehicleApproaching	= 95,
	asn_CauseCodeType_hazardousLocation_DangerousCurve	= 96,
	asn_CauseCodeType_collisionRisk	= 97,
	asn_CauseCodeType_signalViolation	= 98,
	asn_CauseCodeType_dangerousSituation	= 99
} e_asn_CauseCodeType;

/* asn_CauseCodeType */
typedef long	 asn_CauseCodeType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_asn_CauseCodeType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_asn_CauseCodeType;
asn_struct_free_f asn_CauseCodeType_free;
asn_struct_print_f asn_CauseCodeType_print;
asn_constr_check_f asn_CauseCodeType_constraint;
per_type_decoder_f asn_CauseCodeType_decode_uper;
per_type_encoder_f asn_CauseCodeType_encode_uper;
per_type_decoder_f asn_CauseCodeType_decode_aper;
per_type_encoder_f asn_CauseCodeType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _asn_CauseCodeType_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
