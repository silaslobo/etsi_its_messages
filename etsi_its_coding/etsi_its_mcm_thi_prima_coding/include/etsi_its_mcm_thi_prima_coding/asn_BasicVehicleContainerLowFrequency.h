/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/input/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_BasicVehicleContainerLowFrequency_H_
#define	_asn_BasicVehicleContainerLowFrequency_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_mcm_thi_prima_coding/asn_VehicleRole.h"
#include "etsi_its_mcm_thi_prima_coding/asn_ExteriorLights.h"
#include "etsi_its_mcm_thi_prima_coding/asn_PathHistory.h"
#include <etsi_its_mcm_thi_prima_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* asn_BasicVehicleContainerLowFrequency */
typedef struct asn_BasicVehicleContainerLowFrequency {
	asn_VehicleRole_t	 vehicleRole;
	asn_ExteriorLights_t	 exteriorLights;
	asn_PathHistory_t	 pathHistory;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} asn_BasicVehicleContainerLowFrequency_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_BasicVehicleContainerLowFrequency;
extern asn_SEQUENCE_specifics_t asn_SPC_asn_BasicVehicleContainerLowFrequency_specs_1;
extern asn_TYPE_member_t asn_MBR_asn_BasicVehicleContainerLowFrequency_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _asn_BasicVehicleContainerLowFrequency_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
