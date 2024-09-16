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

#include <etsi_its_mapem_ts_coding/mapem_ts_ConnectionManeuverAssist.h>
#include <etsi_its_mapem_ts_coding/regional[].h>
#include <etsi_its_primitives_conversion/convertregional[].h>
#include <etsi_its_mapem_ts_conversion/convertLaneConnectionID.h>
#include <etsi_its_mapem_ts_conversion/convertPedestrianBicycleDetect.h>
#include <etsi_its_mapem_ts_conversion/convertWaitOnStopline.h>
#include <etsi_its_mapem_ts_conversion/convertZoneLength.h>
#ifdef ROS1
#include <etsi_its_mapem_ts_msgs/ConnectionManeuverAssist.h>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs;
#else
#include <etsi_its_mapem_ts_msgs/msg/connection_maneuver_assist.hpp>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs::msg;
#endif


namespace etsi_its_mapem_ts_conversion {

void toRos_ConnectionManeuverAssist(const mapem_ts_ConnectionManeuverAssist_t& in, mapem_ts_msgs::ConnectionManeuverAssist& out) {
  toRos_LaneConnectionID(in.connectionID, out.connection_id);
  if (in.queueLength) {
    toRos_ZoneLength(*in.queueLength, out.queue_length);
    out.queue_length_is_present = true;
  }
  if (in.availableStorageLength) {
    toRos_ZoneLength(*in.availableStorageLength, out.available_storage_length);
    out.available_storage_length_is_present = true;
  }
  if (in.waitOnStop) {
    toRos_WaitOnStopline(*in.waitOnStop, out.wait_on_stop);
    out.wait_on_stop_is_present = true;
  }
  if (in.pedBicycleDetect) {
    toRos_PedestrianBicycleDetect(*in.pedBicycleDetect, out.ped_bicycle_detect);
    out.ped_bicycle_detect_is_present = true;
  }
  if (in.regional) {
    etsi_its_primitives_conversion::toRos_regional[](*in.regional, out.regional);
    out.regional_is_present = true;
  }
}

void toStruct_ConnectionManeuverAssist(const mapem_ts_msgs::ConnectionManeuverAssist& in, mapem_ts_ConnectionManeuverAssist_t& out) {
  memset(&out, 0, sizeof(mapem_ts_ConnectionManeuverAssist_t));

  toStruct_LaneConnectionID(in.connection_id, out.connectionID);
  if (in.queue_length_is_present) {
    out.queueLength = (mapem_ts_ZoneLength_t*) calloc(1, sizeof(mapem_ts_ZoneLength_t));
    toStruct_ZoneLength(in.queue_length, *out.queueLength);
  }
  if (in.available_storage_length_is_present) {
    out.availableStorageLength = (mapem_ts_ZoneLength_t*) calloc(1, sizeof(mapem_ts_ZoneLength_t));
    toStruct_ZoneLength(in.available_storage_length, *out.availableStorageLength);
  }
  if (in.wait_on_stop_is_present) {
    out.waitOnStop = (mapem_ts_WaitOnStopline_t*) calloc(1, sizeof(mapem_ts_WaitOnStopline_t));
    toStruct_WaitOnStopline(in.wait_on_stop, *out.waitOnStop);
  }
  if (in.ped_bicycle_detect_is_present) {
    out.pedBicycleDetect = (mapem_ts_PedestrianBicycleDetect_t*) calloc(1, sizeof(mapem_ts_PedestrianBicycleDetect_t));
    toStruct_PedestrianBicycleDetect(in.ped_bicycle_detect, *out.pedBicycleDetect);
  }
  if (in.regional_is_present) {
    out.regional = (regional[]_t*) calloc(1, sizeof(regional[]_t));
    etsi_its_primitives_conversion::toStruct_regional[](in.regional, *out.regional);
  }
}

}
