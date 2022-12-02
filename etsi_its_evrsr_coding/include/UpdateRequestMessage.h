/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "/input/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_UpdateRequestMessage_H_
#define	_UpdateRequestMessage_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Reservation-ID.h"
#include "Reservation-Password.h"
#include "TimestampUTC.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UpdateRequestMessage */
typedef struct UpdateRequestMessage {
	Reservation_ID_t	 reservation_ID;
	Reservation_Password_t	 reservation_Password;
	TimestampUTC_t	 updatedArrivalTime;
	TimestampUTC_t	 updatedDepartureTime;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UpdateRequestMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UpdateRequestMessage;
extern asn_SEQUENCE_specifics_t asn_SPC_UpdateRequestMessage_specs_1;
extern asn_TYPE_member_t asn_MBR_UpdateRequestMessage_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _UpdateRequestMessage_H_ */
#include <asn_internal.h>
