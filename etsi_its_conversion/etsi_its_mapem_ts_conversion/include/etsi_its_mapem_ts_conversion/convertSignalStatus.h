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

#include <etsi_its_mapem_ts_coding/mapem_ts_SignalStatus.h>
#include <etsi_its_mapem_ts_coding/regional[].h>
#include <etsi_its_primitives_conversion/convertregional[].h>
#include <etsi_its_mapem_ts_conversion/convertIntersectionReferenceID.h>
#include <etsi_its_mapem_ts_conversion/convertMsgCount.h>
#include <etsi_its_mapem_ts_conversion/convertSignalStatusPackageList.h>
#ifdef ROS1
#include <etsi_its_mapem_ts_msgs/SignalStatus.h>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs;
#else
#include <etsi_its_mapem_ts_msgs/msg/signal_status.hpp>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs::msg;
#endif


namespace etsi_its_mapem_ts_conversion {

void toRos_SignalStatus(const mapem_ts_SignalStatus_t& in, mapem_ts_msgs::SignalStatus& out) {
  toRos_MsgCount(in.sequenceNumber, out.sequence_number);
  toRos_IntersectionReferenceID(in.id, out.id);
  toRos_SignalStatusPackageList(in.sigStatus, out.sig_status);
  if (in.regional) {
    etsi_its_primitives_conversion::toRos_regional[](*in.regional, out.regional);
    out.regional_is_present = true;
  }
}

void toStruct_SignalStatus(const mapem_ts_msgs::SignalStatus& in, mapem_ts_SignalStatus_t& out) {
  memset(&out, 0, sizeof(mapem_ts_SignalStatus_t));

  toStruct_MsgCount(in.sequence_number, out.sequenceNumber);
  toStruct_IntersectionReferenceID(in.id, out.id);
  toStruct_SignalStatusPackageList(in.sig_status, out.sigStatus);
  if (in.regional_is_present) {
    out.regional = (regional[]_t*) calloc(1, sizeof(regional[]_t));
    etsi_its_primitives_conversion::toStruct_regional[](in.regional, *out.regional);
  }
}

}
