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

#include <etsi_its_mapem_ts_coding/mapem_ts_NodeAttributeSetXY.h>
#include <etsi_its_mapem_ts_coding/regional[].h>
#include <etsi_its_primitives_conversion/convertregional[].h>
#include <etsi_its_mapem_ts_conversion/convertLaneDataAttributeList.h>
#include <etsi_its_mapem_ts_conversion/convertNodeAttributeXYList.h>
#include <etsi_its_mapem_ts_conversion/convertOffsetB10.h>
#include <etsi_its_mapem_ts_conversion/convertSegmentAttributeXYList.h>
#ifdef ROS1
#include <etsi_its_mapem_ts_msgs/NodeAttributeSetXY.h>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs;
#else
#include <etsi_its_mapem_ts_msgs/msg/node_attribute_set_xy.hpp>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs::msg;
#endif


namespace etsi_its_mapem_ts_conversion {

void toRos_NodeAttributeSetXY(const mapem_ts_NodeAttributeSetXY_t& in, mapem_ts_msgs::NodeAttributeSetXY& out) {
  if (in.localNode) {
    toRos_NodeAttributeXYList(*in.localNode, out.local_node);
    out.local_node_is_present = true;
  }
  if (in.disabled) {
    toRos_SegmentAttributeXYList(*in.disabled, out.disabled);
    out.disabled_is_present = true;
  }
  if (in.enabled) {
    toRos_SegmentAttributeXYList(*in.enabled, out.enabled);
    out.enabled_is_present = true;
  }
  if (in.data) {
    toRos_LaneDataAttributeList(*in.data, out.data);
    out.data_is_present = true;
  }
  if (in.dWidth) {
    toRos_OffsetB10(*in.dWidth, out.d_width);
    out.d_width_is_present = true;
  }
  if (in.dElevation) {
    toRos_OffsetB10(*in.dElevation, out.d_elevation);
    out.d_elevation_is_present = true;
  }
  if (in.regional) {
    etsi_its_primitives_conversion::toRos_regional[](*in.regional, out.regional);
    out.regional_is_present = true;
  }
}

void toStruct_NodeAttributeSetXY(const mapem_ts_msgs::NodeAttributeSetXY& in, mapem_ts_NodeAttributeSetXY_t& out) {
  memset(&out, 0, sizeof(mapem_ts_NodeAttributeSetXY_t));

  if (in.local_node_is_present) {
    out.localNode = (mapem_ts_NodeAttributeXYList_t*) calloc(1, sizeof(mapem_ts_NodeAttributeXYList_t));
    toStruct_NodeAttributeXYList(in.local_node, *out.localNode);
  }
  if (in.disabled_is_present) {
    out.disabled = (mapem_ts_SegmentAttributeXYList_t*) calloc(1, sizeof(mapem_ts_SegmentAttributeXYList_t));
    toStruct_SegmentAttributeXYList(in.disabled, *out.disabled);
  }
  if (in.enabled_is_present) {
    out.enabled = (mapem_ts_SegmentAttributeXYList_t*) calloc(1, sizeof(mapem_ts_SegmentAttributeXYList_t));
    toStruct_SegmentAttributeXYList(in.enabled, *out.enabled);
  }
  if (in.data_is_present) {
    out.data = (mapem_ts_LaneDataAttributeList_t*) calloc(1, sizeof(mapem_ts_LaneDataAttributeList_t));
    toStruct_LaneDataAttributeList(in.data, *out.data);
  }
  if (in.d_width_is_present) {
    out.dWidth = (mapem_ts_OffsetB10_t*) calloc(1, sizeof(mapem_ts_OffsetB10_t));
    toStruct_OffsetB10(in.d_width, *out.dWidth);
  }
  if (in.d_elevation_is_present) {
    out.dElevation = (mapem_ts_OffsetB10_t*) calloc(1, sizeof(mapem_ts_OffsetB10_t));
    toStruct_OffsetB10(in.d_elevation, *out.dElevation);
  }
  if (in.regional_is_present) {
    out.regional = (regional[]_t*) calloc(1, sizeof(regional[]_t));
    etsi_its_primitives_conversion::toStruct_regional[](in.regional, *out.regional);
  }
}

}
