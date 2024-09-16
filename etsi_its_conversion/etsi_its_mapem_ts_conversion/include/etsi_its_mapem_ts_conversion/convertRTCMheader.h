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

#include <etsi_its_mapem_ts_coding/mapem_ts_RTCMheader.h>
#include <etsi_its_mapem_ts_conversion/convertAntennaOffsetSet.h>
#include <etsi_its_mapem_ts_conversion/convertGNSSstatus.h>
#ifdef ROS1
#include <etsi_its_mapem_ts_msgs/RTCMheader.h>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs;
#else
#include <etsi_its_mapem_ts_msgs/msg/rtc_mheader.hpp>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs::msg;
#endif


namespace etsi_its_mapem_ts_conversion {

void toRos_RTCMheader(const mapem_ts_RTCMheader_t& in, mapem_ts_msgs::RTCMheader& out) {
  toRos_GNSSstatus(in.status, out.status);
  toRos_AntennaOffsetSet(in.offsetSet, out.offset_set);
}

void toStruct_RTCMheader(const mapem_ts_msgs::RTCMheader& in, mapem_ts_RTCMheader_t& out) {
  memset(&out, 0, sizeof(mapem_ts_RTCMheader_t));

  toStruct_GNSSstatus(in.status, out.status);
  toStruct_AntennaOffsetSet(in.offset_set, out.offsetSet);
}

}
