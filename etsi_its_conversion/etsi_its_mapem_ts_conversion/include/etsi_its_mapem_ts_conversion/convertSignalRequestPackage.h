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

#include <etsi_its_mapem_ts_coding/mapem_ts_SignalRequestPackage.h>
#include <etsi_its_mapem_ts_coding/regional[].h>
#include <etsi_its_primitives_conversion/convertregional[].h>
#include <etsi_its_mapem_ts_conversion/convertDSecond.h>
#include <etsi_its_mapem_ts_conversion/convertMinuteOfTheYear.h>
#include <etsi_its_mapem_ts_conversion/convertSignalRequest.h>
#ifdef ROS1
#include <etsi_its_mapem_ts_msgs/SignalRequestPackage.h>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs;
#else
#include <etsi_its_mapem_ts_msgs/msg/signal_request_package.hpp>
namespace mapem_ts_msgs = etsi_its_mapem_ts_msgs::msg;
#endif


namespace etsi_its_mapem_ts_conversion {

void toRos_SignalRequestPackage(const mapem_ts_SignalRequestPackage_t& in, mapem_ts_msgs::SignalRequestPackage& out) {
  toRos_SignalRequest(in.request, out.request);
  if (in.minute) {
    toRos_MinuteOfTheYear(*in.minute, out.minute);
    out.minute_is_present = true;
  }
  if (in.second) {
    toRos_DSecond(*in.second, out.second);
    out.second_is_present = true;
  }
  if (in.duration) {
    toRos_DSecond(*in.duration, out.duration);
    out.duration_is_present = true;
  }
  if (in.regional) {
    etsi_its_primitives_conversion::toRos_regional[](*in.regional, out.regional);
    out.regional_is_present = true;
  }
}

void toStruct_SignalRequestPackage(const mapem_ts_msgs::SignalRequestPackage& in, mapem_ts_SignalRequestPackage_t& out) {
  memset(&out, 0, sizeof(mapem_ts_SignalRequestPackage_t));

  toStruct_SignalRequest(in.request, out.request);
  if (in.minute_is_present) {
    out.minute = (mapem_ts_MinuteOfTheYear_t*) calloc(1, sizeof(mapem_ts_MinuteOfTheYear_t));
    toStruct_MinuteOfTheYear(in.minute, *out.minute);
  }
  if (in.second_is_present) {
    out.second = (mapem_ts_DSecond_t*) calloc(1, sizeof(mapem_ts_DSecond_t));
    toStruct_DSecond(in.second, *out.second);
  }
  if (in.duration_is_present) {
    out.duration = (mapem_ts_DSecond_t*) calloc(1, sizeof(mapem_ts_DSecond_t));
    toStruct_DSecond(in.duration, *out.duration);
  }
  if (in.regional_is_present) {
    out.regional = (regional[]_t*) calloc(1, sizeof(regional[]_t));
    etsi_its_primitives_conversion::toStruct_regional[](in.regional, *out.regional);
  }
}

}
