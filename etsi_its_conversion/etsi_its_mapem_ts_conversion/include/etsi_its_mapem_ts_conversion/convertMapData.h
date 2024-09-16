/** ============================================================================
MIT License

Copyright (c) 2023-2024 Institute for Automotive Engineering (ika), RWTH Aachen University
Copyright (c) 2024 Instituto de Telecomunicações, Universidade de Aveiro

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
============================================================================= */

// --- Auto-generated by asn1ToConversionHeader.py -----------------------------

#pragma once

#include <etsi_its_mapem_ts_coding/mapem_ts_MapData.h>
#include <etsi_its_mapem_ts_coding/regional[].h>
#include <etsi_its_primitives_conversion/convertregional[].h>
#include <etsi_its_mapem_ts_conversion/convertDataParameters.h>
#include <etsi_its_mapem_ts_conversion/convertIntersectionGeometryList.h>
#include <etsi_its_mapem_ts_conversion/convertLayerID.h>
#include <etsi_its_mapem_ts_conversion/convertLayerType.h>
#include <etsi_its_mapem_ts_conversion/convertMinuteOfTheYear.h>
#include <etsi_its_mapem_ts_conversion/convertMsgCount.h>
#include <etsi_its_mapem_ts_conversion/convertRestrictionClassList.h>
#include <etsi_its_mapem_ts_conversion/convertRoadSegmentList.h>
#ifdef ROS1
#include <etsi_its_mapem_ts_msgs/MapData.h>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs;
#else
#include <etsi_its_mapem_ts_msgs/msg/map_data.hpp>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs::msg;
#endif


namespace etsi_its_mapem_ts_conversion {

void toRos_MapData(const mapem_ts_MapData_t& in, mapem_ts_msgs::MapData& out) {
  if (in.timeStamp) {
    toRos_MinuteOfTheYear(*in.timeStamp, out.time_stamp);
    out.time_stamp_is_present = true;
  }
  toRos_MsgCount(in.msgIssueRevision, out.msg_issue_revision);
  if (in.layerType) {
    toRos_LayerType(*in.layerType, out.layer_type);
    out.layer_type_is_present = true;
  }
  if (in.layerID) {
    toRos_LayerID(*in.layerID, out.layer_id);
    out.layer_id_is_present = true;
  }
  if (in.intersections) {
    toRos_IntersectionGeometryList(*in.intersections, out.intersections);
    out.intersections_is_present = true;
  }
  if (in.roadSegments) {
    toRos_RoadSegmentList(*in.roadSegments, out.road_segments);
    out.road_segments_is_present = true;
  }
  if (in.dataParameters) {
    toRos_DataParameters(*in.dataParameters, out.data_parameters);
    out.data_parameters_is_present = true;
  }
  if (in.restrictionList) {
    toRos_RestrictionClassList(*in.restrictionList, out.restriction_list);
    out.restriction_list_is_present = true;
  }
  if (in.regional) {
    etsi_its_primitives_conversion::toRos_regional[](*in.regional, out.regional);
    out.regional_is_present = true;
  }
}

void toStruct_MapData(const mapem_ts_msgs::MapData& in, mapem_ts_MapData_t& out) {
  memset(&out, 0, sizeof(mapem_ts_MapData_t));

  if (in.time_stamp_is_present) {
    out.timeStamp = (mapem_ts_MinuteOfTheYear_t*) calloc(1, sizeof(mapem_ts_MinuteOfTheYear_t));
    toStruct_MinuteOfTheYear(in.time_stamp, *out.timeStamp);
  }
  toStruct_MsgCount(in.msg_issue_revision, out.msgIssueRevision);
  if (in.layer_type_is_present) {
    out.layerType = (mapem_ts_LayerType_t*) calloc(1, sizeof(mapem_ts_LayerType_t));
    toStruct_LayerType(in.layer_type, *out.layerType);
  }
  if (in.layer_id_is_present) {
    out.layerID = (mapem_ts_LayerID_t*) calloc(1, sizeof(mapem_ts_LayerID_t));
    toStruct_LayerID(in.layer_id, *out.layerID);
  }
  if (in.intersections_is_present) {
    out.intersections = (mapem_ts_IntersectionGeometryList_t*) calloc(1, sizeof(mapem_ts_IntersectionGeometryList_t));
    toStruct_IntersectionGeometryList(in.intersections, *out.intersections);
  }
  if (in.road_segments_is_present) {
    out.roadSegments = (mapem_ts_RoadSegmentList_t*) calloc(1, sizeof(mapem_ts_RoadSegmentList_t));
    toStruct_RoadSegmentList(in.road_segments, *out.roadSegments);
  }
  if (in.data_parameters_is_present) {
    out.dataParameters = (mapem_ts_DataParameters_t*) calloc(1, sizeof(mapem_ts_DataParameters_t));
    toStruct_DataParameters(in.data_parameters, *out.dataParameters);
  }
  if (in.restriction_list_is_present) {
    out.restrictionList = (mapem_ts_RestrictionClassList_t*) calloc(1, sizeof(mapem_ts_RestrictionClassList_t));
    toStruct_RestrictionClassList(in.restriction_list, *out.restrictionList);
  }
  if (in.regional_is_present) {
    out.regional = (regional[]_t*) calloc(1, sizeof(regional[]_t));
    etsi_its_primitives_conversion::toStruct_regional[](in.regional, *out.regional);
  }
}

}
