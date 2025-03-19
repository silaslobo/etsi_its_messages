/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "/input/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_ManeuverExecutionContainer_H_
#define	_asn_ManeuverExecutionContainer_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_mcm_thi_prima_coding/asn_McmCategory.h"
#include "etsi_its_mcm_thi_prima_coding/asn_PriorityManeuver.h"
#include "etsi_its_mcm_thi_prima_coding/asn_CooperationID.h"
#include "etsi_its_mcm_thi_prima_coding/asn_StationID.h"
#include <etsi_its_mcm_thi_prima_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* asn_ManeuverExecutionContainer */
typedef struct asn_ManeuverExecutionContainer {
	asn_McmCategory_t	 mcmCategory;
	asn_PriorityManeuver_t	 priorityManeuver;
	asn_CooperationID_t	 cooperationID;
	asn_StationID_t	 cooperationVehicleID1;
	asn_StationID_t	*cooperationVehicleID2;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} asn_ManeuverExecutionContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_ManeuverExecutionContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_asn_ManeuverExecutionContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_asn_ManeuverExecutionContainer_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _asn_ManeuverExecutionContainer_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
