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

//// SEQUENCE PathPoint


#pragma once

#include <stdexcept>

#include <etsi_its_denm_coding/PathPoint.h>
#include <etsi_its_denm_conversion/convertDeltaReferencePosition.h>
#include <etsi_its_denm_conversion/convertPathDeltaTime.h>
#ifdef ROS1
#include <etsi_its_denm_msgs/PathPoint.h>
namespace denm_msgs = etsi_its_denm_msgs;
#else
#include <etsi_its_denm_msgs/msg/path_point.hpp>
namespace denm_msgs = etsi_its_denm_msgs::msg;
#endif


namespace etsi_its_denm_conversion {

void toRos_PathPoint(const PathPoint_t& in, denm_msgs::PathPoint& out) {
  toRos_DeltaReferencePosition(in.pathPosition, out.path_position);
  if (in.pathDeltaTime) {
    toRos_PathDeltaTime(*in.pathDeltaTime, out.path_delta_time);
    out.path_delta_time_is_present = true;
  }
}

void toStruct_PathPoint(const denm_msgs::PathPoint& in, PathPoint_t& out) {
  memset(&out, 0, sizeof(PathPoint_t));

  toStruct_DeltaReferencePosition(in.path_position, out.pathPosition);
  if (in.path_delta_time_is_present) {
    out.pathDeltaTime = (PathDeltaTime_t*) calloc(1, sizeof(PathDeltaTime_t));
    toStruct_PathDeltaTime(in.path_delta_time, *out.pathDeltaTime);
  }
}

}
