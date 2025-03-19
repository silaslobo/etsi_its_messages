/** ============================================================================
MIT License

Copyright (c) 2023-2025 Institute for Automotive Engineering (ika), RWTH Aachen University

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

/** Auto-generated by https://github.com/ika-rwth-aachen/etsi_its_messages -----
python3 \
  asn1ToConversionHeader.py \
  -t \
  asn \
  /home/lobo/Development/etsi_its_message/ros2_ws/src/etsi_its_messages/asn1/raw/mcm_thi_prima/cdd/ITS-Container.asn \
  /home/lobo/Development/etsi_its_message/ros2_ws/src/etsi_its_messages/asn1/raw/cam_en302637_2/CAM-PDU-Descriptions.asn \
  /home/lobo/Development/etsi_its_message/ros2_ws/src/etsi_its_messages/asn1/raw/mcm_thi_prima/MCM-PDU-Descriptions.asn \
  -o \
  /home/lobo/mcm_conversion/
----------------------------------------------------------------------------- */

/** ASN.1 Definition -----------------------------------------------------------
ManeuverCoordinationContainer ::= SEQUENCE {    
    maneuverNegotiationContainer ManeuverNegotiationContainer OPTIONAL,
    maneuverExecutionContainer ManeuverExecutionContainer OPTIONAL	
}
----------------------------------------------------------------------------- */

#pragma once

#include <etsi_its_asn_coding/asn_ManeuverCoordinationContainer.h>
#include <etsi_its_asn_conversion/convertManeuverExecutionContainer.h>
#include <etsi_its_asn_conversion/convertManeuverNegotiationContainer.h>
#ifdef ROS1
#include <etsi_its_asn_msgs/ManeuverCoordinationContainer.h>
namespace asn_msgs = etsi_its_asn_msgs;
#else
#include <etsi_its_asn_msgs/msg/maneuver_coordination_container.hpp>
namespace asn_msgs = etsi_its_asn_msgs::msg;
#endif


namespace etsi_its_asn_conversion {

void toRos_ManeuverCoordinationContainer(const asn_ManeuverCoordinationContainer_t& in, asn_msgs::ManeuverCoordinationContainer& out) {
  if (in.maneuverNegotiationContainer) {
    toRos_ManeuverNegotiationContainer(*in.maneuverNegotiationContainer, out.maneuver_negotiation_container);
    out.maneuver_negotiation_container_is_present = true;
  }
  if (in.maneuverExecutionContainer) {
    toRos_ManeuverExecutionContainer(*in.maneuverExecutionContainer, out.maneuver_execution_container);
    out.maneuver_execution_container_is_present = true;
  }
}

void toStruct_ManeuverCoordinationContainer(const asn_msgs::ManeuverCoordinationContainer& in, asn_ManeuverCoordinationContainer_t& out) {
  memset(&out, 0, sizeof(asn_ManeuverCoordinationContainer_t));
  if (in.maneuver_negotiation_container_is_present) {
    out.maneuverNegotiationContainer = (asn_ManeuverNegotiationContainer_t*) calloc(1, sizeof(asn_ManeuverNegotiationContainer_t));
    toStruct_ManeuverNegotiationContainer(in.maneuver_negotiation_container, *out.maneuverNegotiationContainer);
  }
  if (in.maneuver_execution_container_is_present) {
    out.maneuverExecutionContainer = (asn_ManeuverExecutionContainer_t*) calloc(1, sizeof(asn_ManeuverExecutionContainer_t));
    toStruct_ManeuverExecutionContainer(in.maneuver_execution_container, *out.maneuverExecutionContainer);
  }
}

}
