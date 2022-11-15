/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/cdd/ITS-Container.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_HazardousLocation_AnimalOnTheRoadSubCauseCode_H_
#define	_HazardousLocation_AnimalOnTheRoadSubCauseCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum HazardousLocation_AnimalOnTheRoadSubCauseCode {
	HazardousLocation_AnimalOnTheRoadSubCauseCode_unavailable	= 0,
	HazardousLocation_AnimalOnTheRoadSubCauseCode_wildAnimals	= 1,
	HazardousLocation_AnimalOnTheRoadSubCauseCode_herdOfAnimals	= 2,
	HazardousLocation_AnimalOnTheRoadSubCauseCode_smallAnimals	= 3,
	HazardousLocation_AnimalOnTheRoadSubCauseCode_largeAnimals	= 4
} e_HazardousLocation_AnimalOnTheRoadSubCauseCode;

/* HazardousLocation-AnimalOnTheRoadSubCauseCode */
typedef long	 HazardousLocation_AnimalOnTheRoadSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HazardousLocation_AnimalOnTheRoadSubCauseCode;
asn_struct_free_f HazardousLocation_AnimalOnTheRoadSubCauseCode_free;
asn_struct_print_f HazardousLocation_AnimalOnTheRoadSubCauseCode_print;
asn_constr_check_f HazardousLocation_AnimalOnTheRoadSubCauseCode_constraint;
ber_type_decoder_f HazardousLocation_AnimalOnTheRoadSubCauseCode_decode_ber;
der_type_encoder_f HazardousLocation_AnimalOnTheRoadSubCauseCode_encode_der;
xer_type_decoder_f HazardousLocation_AnimalOnTheRoadSubCauseCode_decode_xer;
xer_type_encoder_f HazardousLocation_AnimalOnTheRoadSubCauseCode_encode_xer;
oer_type_decoder_f HazardousLocation_AnimalOnTheRoadSubCauseCode_decode_oer;
oer_type_encoder_f HazardousLocation_AnimalOnTheRoadSubCauseCode_encode_oer;
per_type_decoder_f HazardousLocation_AnimalOnTheRoadSubCauseCode_decode_uper;
per_type_encoder_f HazardousLocation_AnimalOnTheRoadSubCauseCode_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _HazardousLocation_AnimalOnTheRoadSubCauseCode_H_ */
#include <asn_internal.h>
