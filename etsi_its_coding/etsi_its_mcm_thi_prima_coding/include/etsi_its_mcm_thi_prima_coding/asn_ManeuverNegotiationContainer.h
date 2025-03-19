/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "/input/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_ManeuverNegotiationContainer_H_
#define	_asn_ManeuverNegotiationContainer_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_mcm_thi_prima_coding/asn_McmCategory.h"
#include "etsi_its_mcm_thi_prima_coding/asn_PriorityManeuver.h"
#include "etsi_its_mcm_thi_prima_coding/asn_CooperationTypeMCM.h"
#include "etsi_its_mcm_thi_prima_coding/asn_RequestID.h"
#include "etsi_its_mcm_thi_prima_coding/asn_TrajectoryMCM.h"
#include "etsi_its_mcm_thi_prima_coding/asn_Reason.h"
#include "etsi_its_mcm_thi_prima_coding/asn_ReasonReject.h"
#include "etsi_its_mcm_thi_prima_coding/asn_CooperationCostTrajectory.h"
#include "etsi_its_mcm_thi_prima_coding/asn_NumberOfVehicles.h"
#include "etsi_its_mcm_thi_prima_coding/asn_StationID.h"
#include <etsi_its_mcm_thi_prima_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct asn_TrajectoryMCM;

/* asn_ManeuverNegotiationContainer */
typedef struct asn_ManeuverNegotiationContainer {
	asn_McmCategory_t	 mcmCategory;
	asn_PriorityManeuver_t	 priorityManeuver;
	asn_CooperationTypeMCM_t	 cooperationTypeMCM;
	asn_RequestID_t	 requestID;
	asn_TrajectoryMCM_t	 requestedTrajectory;
	asn_TrajectoryMCM_t	 offeredTrajectory;
	struct asn_TrajectoryMCM	*alternativeTrajectory;	/* OPTIONAL */
	asn_Reason_t	*reasonRequest;	/* OPTIONAL */
	asn_ReasonReject_t	*reasonReject;	/* OPTIONAL */
	asn_CooperationCostTrajectory_t	*cooperationCostTrajectory;	/* OPTIONAL */
	asn_NumberOfVehicles_t	 numberOfVehicles;
	asn_StationID_t	 negotiationVehicleID1;
	asn_StationID_t	*negotiationVehicleID2;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} asn_ManeuverNegotiationContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_ManeuverNegotiationContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_asn_ManeuverNegotiationContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_asn_ManeuverNegotiationContainer_1[13];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "etsi_its_mcm_thi_prima_coding/asn_TrajectoryMCM.h"

#endif	/* _asn_ManeuverNegotiationContainer_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
