/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_ActionID_H_
#define	_asn_ActionID_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_mcm_thi_prima_coding/asn_StationID.h"
#include "etsi_its_mcm_thi_prima_coding/asn_SequenceNumber.h"
#include <etsi_its_mcm_thi_prima_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* asn_ActionID */
typedef struct asn_ActionID {
	asn_StationID_t	 originatingStationID;
	asn_SequenceNumber_t	 sequenceNumber;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} asn_ActionID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_ActionID;

#ifdef __cplusplus
}
#endif

#endif	/* _asn_ActionID_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
