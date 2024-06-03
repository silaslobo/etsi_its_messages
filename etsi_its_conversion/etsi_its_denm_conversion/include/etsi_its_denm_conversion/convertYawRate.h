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

//// SEQUENCE YawRate


#pragma once

#include <stdexcept>

#include <etsi_its_denm_coding/YawRate.h>
#include <etsi_its_denm_conversion/convertYawRateValue.h>
#include <etsi_its_denm_conversion/convertYawRateConfidence.h>
#ifdef ROS1
#include <etsi_its_denm_msgs/YawRate.h>
namespace denm_msgs = etsi_its_denm_msgs;
#else
#include <etsi_its_denm_msgs/msg/yaw_rate.hpp>
namespace denm_msgs = etsi_its_denm_msgs::msg;
#endif


namespace etsi_its_denm_conversion {

void toRos_YawRate(const YawRate_t& in, denm_msgs::YawRate& out) {
  toRos_YawRateValue(in.yawRateValue, out.yaw_rate_value);
  toRos_YawRateConfidence(in.yawRateConfidence, out.yaw_rate_confidence);
}

void toStruct_YawRate(const denm_msgs::YawRate& in, YawRate_t& out) {
  memset(&out, 0, sizeof(YawRate_t));

  toStruct_YawRateValue(in.yaw_rate_value, out.yawRateValue);
  toStruct_YawRateConfidence(in.yaw_rate_confidence, out.yawRateConfidence);
}

}
