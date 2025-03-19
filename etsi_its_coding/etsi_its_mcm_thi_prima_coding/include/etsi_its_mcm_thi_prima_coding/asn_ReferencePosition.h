/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_ReferencePosition_H_
#define	_asn_ReferencePosition_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_mcm_thi_prima_coding/asn_Latitude.h"
#include "etsi_its_mcm_thi_prima_coding/asn_Longitude.h"
#include "etsi_its_mcm_thi_prima_coding/asn_PosConfidenceEllipse.h"
#include "etsi_its_mcm_thi_prima_coding/asn_Altitude.h"
#include <etsi_its_mcm_thi_prima_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* asn_ReferencePosition */
typedef struct asn_ReferencePosition {
	asn_Latitude_t	 latitude;
	asn_Longitude_t	 longitude;
	asn_PosConfidenceEllipse_t	 positionConfidenceEllipse;
	asn_Altitude_t	 altitude;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} asn_ReferencePosition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_ReferencePosition;
extern asn_SEQUENCE_specifics_t asn_SPC_asn_ReferencePosition_specs_1;
extern asn_TYPE_member_t asn_MBR_asn_ReferencePosition_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _asn_ReferencePosition_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
