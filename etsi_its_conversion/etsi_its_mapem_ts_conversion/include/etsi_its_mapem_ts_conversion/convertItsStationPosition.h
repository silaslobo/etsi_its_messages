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

#include <etsi_its_mapem_ts_coding/mapem_ts_ItsStationPosition.h>
#include <etsi_its_mapem_ts_conversion/convertLaneID.h>
#include <etsi_its_mapem_ts_conversion/convertNodeOffsetPointXY.h>
#include <etsi_its_mapem_ts_conversion/convertStationID.h>
#include <etsi_its_mapem_ts_conversion/convertTimeReference.h>
#ifdef ROS1
#include <etsi_its_mapem_ts_msgs/ItsStationPosition.h>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs;
#else
#include <etsi_its_mapem_ts_msgs/msg/its_station_position.hpp>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs::msg;
#endif


namespace etsi_its_mapem_ts_conversion {

void toRos_ItsStationPosition(const mapem_ts_ItsStationPosition_t& in, mapem_ts_msgs::ItsStationPosition& out) {
  toRos_StationID(in.stationID, out.station_id);
  if (in.laneID) {
    toRos_LaneID(*in.laneID, out.lane_id);
    out.lane_id_is_present = true;
  }
  if (in.nodeXY) {
    toRos_NodeOffsetPointXY(*in.nodeXY, out.node_xy);
    out.node_xy_is_present = true;
  }
  if (in.timeReference) {
    toRos_TimeReference(*in.timeReference, out.time_reference);
    out.time_reference_is_present = true;
  }
}

void toStruct_ItsStationPosition(const mapem_ts_msgs::ItsStationPosition& in, mapem_ts_ItsStationPosition_t& out) {
  memset(&out, 0, sizeof(mapem_ts_ItsStationPosition_t));

  toStruct_StationID(in.station_id, out.stationID);
  if (in.lane_id_is_present) {
    out.laneID = (mapem_ts_LaneID_t*) calloc(1, sizeof(mapem_ts_LaneID_t));
    toStruct_LaneID(in.lane_id, *out.laneID);
  }
  if (in.node_xy_is_present) {
    out.nodeXY = (mapem_ts_NodeOffsetPointXY_t*) calloc(1, sizeof(mapem_ts_NodeOffsetPointXY_t));
    toStruct_NodeOffsetPointXY(in.node_xy, *out.nodeXY);
  }
  if (in.time_reference_is_present) {
    out.timeReference = (mapem_ts_TimeReference_t*) calloc(1, sizeof(mapem_ts_TimeReference_t));
    toStruct_TimeReference(in.time_reference, *out.timeReference);
  }
}

}
