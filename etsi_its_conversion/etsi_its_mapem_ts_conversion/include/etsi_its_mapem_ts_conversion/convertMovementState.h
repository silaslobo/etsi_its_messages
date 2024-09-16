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

#include <etsi_its_mapem_ts_coding/mapem_ts_MovementState.h>
#include <etsi_its_mapem_ts_coding/regional[].h>
#include <etsi_its_primitives_conversion/convertregional[].h>
#include <etsi_its_mapem_ts_conversion/convertDescriptiveName.h>
#include <etsi_its_mapem_ts_conversion/convertManeuverAssistList.h>
#include <etsi_its_mapem_ts_conversion/convertMovementEventList.h>
#include <etsi_its_mapem_ts_conversion/convertSignalGroupID.h>
#ifdef ROS1
#include <etsi_its_mapem_ts_msgs/MovementState.h>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs;
#else
#include <etsi_its_mapem_ts_msgs/msg/movement_state.hpp>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs::msg;
#endif


namespace etsi_its_mapem_ts_conversion {

void toRos_MovementState(const mapem_ts_MovementState_t& in, mapem_ts_msgs::MovementState& out) {
  if (in.movementName) {
    toRos_DescriptiveName(*in.movementName, out.movement_name);
    out.movement_name_is_present = true;
  }
  toRos_SignalGroupID(in.signalGroup, out.signal_group);
  toRos_MovementEventList(in.state-time-speed, out.state_time_speed);
  if (in.maneuverAssistList) {
    toRos_ManeuverAssistList(*in.maneuverAssistList, out.maneuver_assist_list);
    out.maneuver_assist_list_is_present = true;
  }
  if (in.regional) {
    etsi_its_primitives_conversion::toRos_regional[](*in.regional, out.regional);
    out.regional_is_present = true;
  }
}

void toStruct_MovementState(const mapem_ts_msgs::MovementState& in, mapem_ts_MovementState_t& out) {
  memset(&out, 0, sizeof(mapem_ts_MovementState_t));

  if (in.movement_name_is_present) {
    out.movementName = (mapem_ts_DescriptiveName_t*) calloc(1, sizeof(mapem_ts_DescriptiveName_t));
    toStruct_DescriptiveName(in.movement_name, *out.movementName);
  }
  toStruct_SignalGroupID(in.signal_group, out.signalGroup);
  toStruct_MovementEventList(in.state_time_speed, out.state-time-speed);
  if (in.maneuver_assist_list_is_present) {
    out.maneuverAssistList = (mapem_ts_ManeuverAssistList_t*) calloc(1, sizeof(mapem_ts_ManeuverAssistList_t));
    toStruct_ManeuverAssistList(in.maneuver_assist_list, *out.maneuverAssistList);
  }
  if (in.regional_is_present) {
    out.regional = (regional[]_t*) calloc(1, sizeof(regional[]_t));
    etsi_its_primitives_conversion::toStruct_regional[](in.regional, *out.regional);
  }
}

}
