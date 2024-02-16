/*
 * Generated by asn1c-0.9.29-DF (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-UPER`
 */


/* Including external dependencies */
#include <etsi_its_cam_coding/NativeInteger.h>
#ifndef	_CollisionRiskSubCauseCode_H_
#define	_CollisionRiskSubCauseCode_H_


#include <etsi_its_cam_coding/asn_application.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CollisionRiskSubCauseCode {
	CollisionRiskSubCauseCode_unavailable	= 0,
	CollisionRiskSubCauseCode_longitudinalCollisionRisk	= 1,
	CollisionRiskSubCauseCode_crossingCollisionRisk	= 2,
	CollisionRiskSubCauseCode_lateralCollisionRisk	= 3,
	CollisionRiskSubCauseCode_vulnerableRoadUser	= 4
} e_CollisionRiskSubCauseCode;

/* CollisionRiskSubCauseCode */
typedef long	 CollisionRiskSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CollisionRiskSubCauseCode;
asn_struct_free_f CollisionRiskSubCauseCode_free;
asn_struct_print_f CollisionRiskSubCauseCode_print;
asn_constr_check_f CollisionRiskSubCauseCode_constraint;
ber_type_decoder_f CollisionRiskSubCauseCode_decode_ber;
der_type_encoder_f CollisionRiskSubCauseCode_encode_der;
xer_type_decoder_f CollisionRiskSubCauseCode_decode_xer;
xer_type_encoder_f CollisionRiskSubCauseCode_encode_xer;
jer_type_encoder_f CollisionRiskSubCauseCode_encode_jer;
oer_type_decoder_f CollisionRiskSubCauseCode_decode_oer;
oer_type_encoder_f CollisionRiskSubCauseCode_encode_oer;
per_type_decoder_f CollisionRiskSubCauseCode_decode_uper;
per_type_encoder_f CollisionRiskSubCauseCode_encode_uper;
per_type_decoder_f CollisionRiskSubCauseCode_decode_aper;
per_type_encoder_f CollisionRiskSubCauseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _CollisionRiskSubCauseCode_H_ */
#include <etsi_its_cam_coding/asn_internal.h>
