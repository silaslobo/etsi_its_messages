/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/input/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_SpecialVehicleContainer_H_
#define	_SpecialVehicleContainer_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PublicTransportContainer.h"
#include "SpecialTransportContainer.h"
#include "DangerousGoodsContainer.h"
#include "RoadWorksContainerBasic.h"
#include "RescueContainer.h"
#include "EmergencyContainer.h"
#include "SafetyCarContainer.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SpecialVehicleContainer_PR {
	SpecialVehicleContainer_PR_NOTHING,	/* No components present */
	SpecialVehicleContainer_PR_publicTransportContainer,
	SpecialVehicleContainer_PR_specialTransportContainer,
	SpecialVehicleContainer_PR_dangerousGoodsContainer,
	SpecialVehicleContainer_PR_roadWorksContainerBasic,
	SpecialVehicleContainer_PR_rescueContainer,
	SpecialVehicleContainer_PR_emergencyContainer,
	SpecialVehicleContainer_PR_safetyCarContainer
	/* Extensions may appear below */
	
} SpecialVehicleContainer_PR;

/* SpecialVehicleContainer */
typedef struct SpecialVehicleContainer {
	SpecialVehicleContainer_PR present;
	union SpecialVehicleContainer_u {
		PublicTransportContainer_t	 publicTransportContainer;
		SpecialTransportContainer_t	 specialTransportContainer;
		DangerousGoodsContainer_t	 dangerousGoodsContainer;
		RoadWorksContainerBasic_t	 roadWorksContainerBasic;
		RescueContainer_t	 rescueContainer;
		EmergencyContainer_t	 emergencyContainer;
		SafetyCarContainer_t	 safetyCarContainer;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SpecialVehicleContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SpecialVehicleContainer;
extern asn_CHOICE_specifics_t asn_SPC_SpecialVehicleContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_SpecialVehicleContainer_1[7];
extern asn_per_constraints_t asn_PER_type_SpecialVehicleContainer_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _SpecialVehicleContainer_H_ */
#include <asn_internal.h>
