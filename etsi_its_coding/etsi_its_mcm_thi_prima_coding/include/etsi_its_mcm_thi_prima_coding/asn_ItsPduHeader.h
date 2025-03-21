/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_ItsPduHeader_H_
#define	_asn_ItsPduHeader_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mcm_thi_prima_coding/NativeInteger.h>
#include "etsi_its_mcm_thi_prima_coding/asn_StationID.h"
#include <etsi_its_mcm_thi_prima_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum asn_ItsPduHeader__messageID {
	asn_ItsPduHeader__messageID_denm	= 1,
	asn_ItsPduHeader__messageID_cam	= 2,
	asn_ItsPduHeader__messageID_poi	= 3,
	asn_ItsPduHeader__messageID_spatem	= 4,
	asn_ItsPduHeader__messageID_mapem	= 5,
	asn_ItsPduHeader__messageID_ivim	= 6,
	asn_ItsPduHeader__messageID_ev_rsr	= 7,
	asn_ItsPduHeader__messageID_tistpgtransaction	= 8,
	asn_ItsPduHeader__messageID_srem	= 9,
	asn_ItsPduHeader__messageID_ssem	= 10,
	asn_ItsPduHeader__messageID_evcsn	= 11,
	asn_ItsPduHeader__messageID_saem	= 12,
	asn_ItsPduHeader__messageID_rtcmem	= 13
} e_asn_ItsPduHeader__messageID;

/* asn_ItsPduHeader */
typedef struct asn_ItsPduHeader {
	long	 protocolVersion;
	long	 messageID;
	asn_StationID_t	 stationID;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} asn_ItsPduHeader_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_ItsPduHeader;
extern asn_SEQUENCE_specifics_t asn_SPC_asn_ItsPduHeader_specs_1;
extern asn_TYPE_member_t asn_MBR_asn_ItsPduHeader_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _asn_ItsPduHeader_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
