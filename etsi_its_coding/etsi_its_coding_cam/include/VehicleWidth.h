/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/cdd/ITS-Container.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_VehicleWidth_H_
#define	_VehicleWidth_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VehicleWidth {
	VehicleWidth_tenCentimeters	= 1,
	VehicleWidth_outOfRange	= 61,
	VehicleWidth_unavailable	= 62
} e_VehicleWidth;

/* VehicleWidth */
typedef long	 VehicleWidth_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_VehicleWidth_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_VehicleWidth;
asn_struct_free_f VehicleWidth_free;
asn_struct_print_f VehicleWidth_print;
asn_constr_check_f VehicleWidth_constraint;
ber_type_decoder_f VehicleWidth_decode_ber;
der_type_encoder_f VehicleWidth_encode_der;
xer_type_decoder_f VehicleWidth_decode_xer;
xer_type_encoder_f VehicleWidth_encode_xer;
oer_type_decoder_f VehicleWidth_decode_oer;
oer_type_encoder_f VehicleWidth_encode_oer;
per_type_decoder_f VehicleWidth_decode_uper;
per_type_encoder_f VehicleWidth_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _VehicleWidth_H_ */
#include <asn_internal.h>
