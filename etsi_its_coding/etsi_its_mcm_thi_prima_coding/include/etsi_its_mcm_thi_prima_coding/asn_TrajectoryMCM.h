/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "/input/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_TrajectoryMCM_H_
#define	_asn_TrajectoryMCM_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/asn_SEQUENCE_OF.h>
#include <etsi_its_mcm_thi_prima_coding/constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct asn_TrajectoryPointMCM;

/* asn_TrajectoryMCM */
typedef struct asn_TrajectoryMCM {
	A_SEQUENCE_OF(struct asn_TrajectoryPointMCM) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} asn_TrajectoryMCM_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_TrajectoryMCM;
extern asn_SET_OF_specifics_t asn_SPC_asn_TrajectoryMCM_specs_1;
extern asn_TYPE_member_t asn_MBR_asn_TrajectoryMCM_1[1];
extern asn_per_constraints_t asn_PER_type_asn_TrajectoryMCM_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "etsi_its_mcm_thi_prima_coding/asn_TrajectoryPointMCM.h"

#endif	/* _asn_TrajectoryMCM_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
