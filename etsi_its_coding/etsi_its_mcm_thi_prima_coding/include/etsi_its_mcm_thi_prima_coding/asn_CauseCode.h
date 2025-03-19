/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=asn_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_asn_CauseCode_H_
#define	_asn_CauseCode_H_


#include <etsi_its_mcm_thi_prima_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_mcm_thi_prima_coding/asn_CauseCodeType.h"
#include "etsi_its_mcm_thi_prima_coding/asn_SubCauseCodeType.h"
#include <etsi_its_mcm_thi_prima_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* asn_CauseCode */
typedef struct asn_CauseCode {
	asn_CauseCodeType_t	 causeCode;
	asn_SubCauseCodeType_t	 subCauseCode;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} asn_CauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_asn_CauseCode;
extern asn_SEQUENCE_specifics_t asn_SPC_asn_CauseCode_specs_1;
extern asn_TYPE_member_t asn_MBR_asn_CauseCode_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _asn_CauseCode_H_ */
#include <etsi_its_mcm_thi_prima_coding/asn_internal.h>
