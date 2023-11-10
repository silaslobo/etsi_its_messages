/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
 * 	found in "/input/ISO-TS-19091-addgrp-C-2018.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_RequestorDescription_addGrpC_H_
#define	_RequestorDescription_addGrpC_H_


#include <etsi_its_spatem_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_spatem_coding/FuelType.h"
#include "etsi_its_spatem_coding/BatteryStatus.h"
#include <etsi_its_spatem_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RequestorDescription-addGrpC */
typedef struct RequestorDescription_addGrpC {
	FuelType_t	*fuel	/* OPTIONAL */;
	BatteryStatus_t	*batteryStatus	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RequestorDescription_addGrpC_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RequestorDescription_addGrpC;

#ifdef __cplusplus
}
#endif

#endif	/* _RequestorDescription_addGrpC_H_ */
#include <etsi_its_spatem_coding/asn_internal.h>
