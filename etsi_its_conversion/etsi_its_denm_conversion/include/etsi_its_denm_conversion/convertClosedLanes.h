/** ============================================================================
MIT License

Copyright (c) 2023 Institute for Automotive Engineering (ika), RWTH Aachen University
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

//// SEQUENCE ClosedLanes


#pragma once

#include <stdexcept>

#include <etsi_its_denm_coding/ClosedLanes.h>
#include <etsi_its_denm_conversion/convertHardShoulderStatus.h>
#include <etsi_its_denm_conversion/convertHardShoulderStatus.h>
#include <etsi_its_denm_conversion/convertDrivingLaneStatus.h>
#ifdef ROS1
#include <etsi_its_denm_msgs/ClosedLanes.h>
namespace denm_msgs = etsi_its_denm_msgs;
#else
#include <etsi_its_denm_msgs/msg/closed_lanes.hpp>
namespace denm_msgs = etsi_its_denm_msgs::msg;
#endif


namespace etsi_its_denm_conversion {

void toRos_ClosedLanes(const ClosedLanes_t& in, denm_msgs::ClosedLanes& out) {
  if (in.innerhardShoulderStatus) {
    toRos_HardShoulderStatus(*in.innerhardShoulderStatus, out.innerhard_shoulder_status);
    out.innerhard_shoulder_status_is_present = true;
  }
  if (in.outerhardShoulderStatus) {
    toRos_HardShoulderStatus(*in.outerhardShoulderStatus, out.outerhard_shoulder_status);
    out.outerhard_shoulder_status_is_present = true;
  }
  if (in.drivingLaneStatus) {
    toRos_DrivingLaneStatus(*in.drivingLaneStatus, out.driving_lane_status);
    out.driving_lane_status_is_present = true;
  }
}

void toStruct_ClosedLanes(const denm_msgs::ClosedLanes& in, ClosedLanes_t& out) {
  memset(&out, 0, sizeof(ClosedLanes_t));

  if (in.innerhard_shoulder_status_is_present) {
    out.innerhardShoulderStatus = (HardShoulderStatus_t*) calloc(1, sizeof(HardShoulderStatus_t));
    toStruct_HardShoulderStatus(in.innerhard_shoulder_status, *out.innerhardShoulderStatus);
  }
  if (in.outerhard_shoulder_status_is_present) {
    out.outerhardShoulderStatus = (HardShoulderStatus_t*) calloc(1, sizeof(HardShoulderStatus_t));
    toStruct_HardShoulderStatus(in.outerhard_shoulder_status, *out.outerhardShoulderStatus);
  }
  if (in.driving_lane_status_is_present) {
    out.drivingLaneStatus = (DrivingLaneStatus_t*) calloc(1, sizeof(DrivingLaneStatus_t));
    toStruct_DrivingLaneStatus(in.driving_lane_status, *out.drivingLaneStatus);
  }
}

}
