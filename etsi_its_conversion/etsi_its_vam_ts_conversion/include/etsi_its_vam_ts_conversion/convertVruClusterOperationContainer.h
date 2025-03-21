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
  utils/codegen/codegen-py/asn1ToConversionHeader.py \
  asn1/raw/vam-ts103300_3/VAM-PDU-Descriptions.asn \
  asn1/patched/vam-ts103300_3/cdd/ETSI-ITS-CDD.asn \
  -t \
  vam_ts \
  -o \
  etsi_its_conversion/etsi_its_vam_ts_conversion/include/etsi_its_vam_ts_conversion
----------------------------------------------------------------------------- */

/** ASN.1 Definition -----------------------------------------------------------
 *
 * @details VruClusterOperationContainer
 * The VRU Cluster Operation container of the VAM provides information relevant to change of cluster state and composition.
 * It is mandatory if the VAM is transmitted by a VRU joining, leaving or breaking up a cluster.
 * It includes the following components (setting indications are specified in clause 7.3.5 of TS 103 300-3). 
 * At least one of the fields below shall be present if the container is present in the VAM: 
 *
 * @field clusterJoinInfo: indicates the intent of an individual VAM transmitter to join a cluster. 
 * @field clusterLeaveInfo : indicates that an individual VAM transmitter has recently left the VRU cluster. 
 * @field clusterBreakupInfo: indicates the intent of a cluster VAM transmitter to stop sending cluster VAMs. 
 * @field clusterIdChangeTimeInfo: indicates the intent of a cluster VAM transmitter to change cluster ID. 
 * 
 * @category: VRU information
 * @revision: V2.2.1
 *
    VruClusterOperationContainer ::= SEQUENCE {
        clusterJoinInfo         ClusterJoinInfo OPTIONAL,
        clusterLeaveInfo        ClusterLeaveInfo OPTIONAL,
        clusterBreakupInfo      ClusterBreakupInfo OPTIONAL,
        clusterIdChangeTimeInfo DeltaTimeQuarterSecond OPTIONAL,
        ...
    }
----------------------------------------------------------------------------- */

#pragma once

#include <etsi_its_vam_ts_coding/vam_ts_VruClusterOperationContainer.h>
#include <etsi_its_vam_ts_conversion/convertClusterBreakupInfo.h>
#include <etsi_its_vam_ts_conversion/convertClusterJoinInfo.h>
#include <etsi_its_vam_ts_conversion/convertClusterLeaveInfo.h>
#include <etsi_its_vam_ts_conversion/convertDeltaTimeQuarterSecond.h>
#ifdef ROS1
#include <etsi_its_vam_ts_msgs/VruClusterOperationContainer.h>
namespace vam_ts_msgs = etsi_its_vam_ts_msgs;
#else
#include <etsi_its_vam_ts_msgs/msg/vru_cluster_operation_container.hpp>
namespace vam_ts_msgs = etsi_its_vam_ts_msgs::msg;
#endif


namespace etsi_its_vam_ts_conversion {

void toRos_VruClusterOperationContainer(const vam_ts_VruClusterOperationContainer_t& in, vam_ts_msgs::VruClusterOperationContainer& out) {
  if (in.clusterJoinInfo) {
    toRos_ClusterJoinInfo(*in.clusterJoinInfo, out.cluster_join_info);
    out.cluster_join_info_is_present = true;
  }
  if (in.clusterLeaveInfo) {
    toRos_ClusterLeaveInfo(*in.clusterLeaveInfo, out.cluster_leave_info);
    out.cluster_leave_info_is_present = true;
  }
  if (in.clusterBreakupInfo) {
    toRos_ClusterBreakupInfo(*in.clusterBreakupInfo, out.cluster_breakup_info);
    out.cluster_breakup_info_is_present = true;
  }
  if (in.clusterIdChangeTimeInfo) {
    toRos_DeltaTimeQuarterSecond(*in.clusterIdChangeTimeInfo, out.cluster_id_change_time_info);
    out.cluster_id_change_time_info_is_present = true;
  }
}

void toStruct_VruClusterOperationContainer(const vam_ts_msgs::VruClusterOperationContainer& in, vam_ts_VruClusterOperationContainer_t& out) {
  memset(&out, 0, sizeof(vam_ts_VruClusterOperationContainer_t));
  if (in.cluster_join_info_is_present) {
    out.clusterJoinInfo = (vam_ts_ClusterJoinInfo_t*) calloc(1, sizeof(vam_ts_ClusterJoinInfo_t));
    toStruct_ClusterJoinInfo(in.cluster_join_info, *out.clusterJoinInfo);
  }
  if (in.cluster_leave_info_is_present) {
    out.clusterLeaveInfo = (vam_ts_ClusterLeaveInfo_t*) calloc(1, sizeof(vam_ts_ClusterLeaveInfo_t));
    toStruct_ClusterLeaveInfo(in.cluster_leave_info, *out.clusterLeaveInfo);
  }
  if (in.cluster_breakup_info_is_present) {
    out.clusterBreakupInfo = (vam_ts_ClusterBreakupInfo_t*) calloc(1, sizeof(vam_ts_ClusterBreakupInfo_t));
    toStruct_ClusterBreakupInfo(in.cluster_breakup_info, *out.clusterBreakupInfo);
  }
  if (in.cluster_id_change_time_info_is_present) {
    out.clusterIdChangeTimeInfo = (vam_ts_DeltaTimeQuarterSecond_t*) calloc(1, sizeof(vam_ts_DeltaTimeQuarterSecond_t));
    toStruct_DeltaTimeQuarterSecond(in.cluster_id_change_time_info, *out.clusterIdChangeTimeInfo);
  }
}

}
