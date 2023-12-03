/** ============================================================================
MIT License

Copyright (c) 2023 Institute for Automotive Engineering (ika), RWTH Aachen University

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

#include <algorithm>
#include <arpa/inet.h>
#include <sstream>

#ifdef ROS1
#include <ros/console.h>
#else
#include <rcutils/logging.h>
#endif

#include "etsi_its_conversion/Converter.hpp"

#ifdef ROS1
#define ROS_LOG(level, ...) NODELET_##level(__VA_ARGS__)
#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(etsi_its_conversion::Converter, nodelet::Nodelet)
#else
#define ROS_LOG(level, ...) RCLCPP_##level(this->get_logger(), __VA_ARGS__)
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(etsi_its_conversion::Converter)
#endif


namespace etsi_its_conversion {

const int kBtpHeaderDestinationPortCam{2001};
const int kBtpHeaderDestinationPortDenm{2002};
const int kBtpHeaderDestinationPortMapem{2003};
const int kBtpHeaderDestinationPortSpatem{2004};
const int kBtpHeaderDestinationPortIvi{2006};
const int kBtpHeaderDestinationPortCpm{2009};

#ifdef ROS1
const std::string Converter::kInputTopicUdp{"udp/in"};
const std::string Converter::kOutputTopicUdp{"udp/out"};
const std::string Converter::kInputTopicCam{"cam/in"};
const std::string Converter::kOutputTopicCam{"cam/out"};
const std::string Converter::kInputTopicDenm{"denm/in"};
const std::string Converter::kOutputTopicDenm{"denm/out"};
const std::string Converter::kInputTopicSpatem{"spatem/in"};
const std::string Converter::kOutputTopicSpatem{"spatem/out"};
const std::string Converter::kInputTopicMapem{"mapem/in"};
const std::string Converter::kOutputTopicMapem{"mapem/out"};
#else
const std::string Converter::kInputTopicUdp{"~/udp/in"};
const std::string Converter::kOutputTopicUdp{"~/udp/out"};
const std::string Converter::kInputTopicCam{"~/cam/in"};
const std::string Converter::kOutputTopicCam{"~/cam/out"};
const std::string Converter::kInputTopicDenm{"~/denm/in"};
const std::string Converter::kOutputTopicDenm{"~/denm/out"};
const std::string Converter::kInputTopicSpatem{"~/spatem/in"};
const std::string Converter::kOutputTopicSpatem{"~/spatem/out"};
const std::string Converter::kInputTopicMapem{"~/mapem/in"};
const std::string Converter::kOutputTopicMapem{"~/mapem/out"};
#endif

const std::string Converter::kEtsiTypeParam{"etsi_type"};
const std::string Converter::kEtsiTypeParamDefault{"auto"};


bool Converter::logLevelIsDebug() {

#ifdef ROS1
  std::map<std::string, ros::console::levels::Level> loggers;
  bool ret = ros::console::get_loggers(loggers);
  std::string node_logger = ROSCONSOLE_DEFAULT_NAME;
  node_logger += "." + ros::this_node::getName();
  if (loggers.count(node_logger) > 0) {
    if (loggers[node_logger] == ros::console::levels::Level::Debug) return true;
  }
  std::string nodelet_logger = "ros.nodelet." + ros::this_node::getName();
  if (loggers.count(nodelet_logger) > 0) {
    if (loggers[nodelet_logger] == ros::console::levels::Level::Debug) return true;
  }
#else
  auto logger_level = rcutils_logging_get_logger_effective_level(this->get_logger().get_name());
  return (logger_level == RCUTILS_LOG_SEVERITY_DEBUG);
#endif

  return false;
}


#ifdef ROS1
void Converter::onInit() {

  private_node_handle_ = this->getMTPrivateNodeHandle();
#else
Converter::Converter(const rclcpp::NodeOptions& options) : Node("converter", options) {
#endif

  this->loadParameters();
  this->setup();
}


void Converter::loadParameters() {

  std::vector<std::string> known_etsi_types = {kEtsiTypeParamDefault, "cam", "denm", "spatem", "mapem"};

#ifdef ROS1
  if (!private_node_handle_.param<std::string>(kEtsiTypeParam, etsi_type_, kEtsiTypeParamDefault)) {
#else
  rcl_interfaces::msg::ParameterDescriptor param_desc;
  std::stringstream ss;
  ss << "ETSI type to convert, one of ";
  for (const auto& e : known_etsi_types) ss << e << ", ";
  param_desc.description = ss.str();
  this->declare_parameter(kEtsiTypeParam, kEtsiTypeParamDefault, param_desc);

  if (!this->get_parameter(kEtsiTypeParam, etsi_type_)) {
#endif
    ROS_LOG(WARN, "Parameter '%s' is not set, defaulting to '%s'", kEtsiTypeParam.c_str(), kEtsiTypeParamDefault.c_str());
  }

  if (std::find(known_etsi_types.begin(), known_etsi_types.end(), etsi_type_) == known_etsi_types.end()) {
    ROS_LOG(WARN, "Invalid value for parameter '%s', defaulting to '%s'", kEtsiTypeParam.c_str(), kEtsiTypeParamDefault.c_str());
  }
}


void Converter::setup() {

  // create subscribers and publishers
#ifdef ROS1
  publisher_udp_ = std::make_shared<ros::Publisher>(private_node_handle_.advertise<UdpPacket>(kOutputTopicUdp, 1));
  publishers_["cam"] = std::make_shared<ros::Publisher>(private_node_handle_.advertise<cam_msgs::CAM>(kOutputTopicCam, 1));
  publishers_["denm"] = std::make_shared<ros::Publisher>(private_node_handle_.advertise<denm_msgs::DENM>(kOutputTopicDenm, 1));
  publishers_["spatem"] = std::make_shared<ros::Publisher>(private_node_handle_.advertise<spatem_msgs::SPATEM>(kOutputTopicSpatem, 1));
  publishers_["mapem"] = std::make_shared<ros::Publisher>(private_node_handle_.advertise<mapem_msgs::MAPEM>(kOutputTopicMapem, 1));
  subscriber_udp_ = std::make_shared<ros::Subscriber>(private_node_handle_.subscribe(kInputTopicUdp, 1, &Converter::udpCallback, this));
  subscribers_["cam"] = std::make_shared<ros::Subscriber>(private_node_handle_.subscribe(kInputTopicCam, 1, &Converter::rosCallbackCam, this));
  subscribers_["denm"] = std::make_shared<ros::Subscriber>(private_node_handle_.subscribe(kInputTopicDenm, 1, &Converter::rosCallbackDenm, this));
  subscribers_["spatem"] = std::make_shared<ros::Subscriber>(private_node_handle_.subscribe(kInputTopicSpatem, 1, &Converter::rosCallbackSpatem, this));
  subscribers_["mapem"] = std::make_shared<ros::Subscriber>(private_node_handle_.subscribe(kInputTopicMapem, 1, &Converter::rosCallbackMapem, this));
  ROS_LOG(INFO, "Converting UDP messages of type '%s' on '%s' to native ROS messages on '%s'", etsi_type_.c_str(), subscriber_udp_->getTopic().c_str(), publishers_["cam"]->getTopic().c_str());
  ROS_LOG(INFO, "Converting native ROS CAMs on '%s' to UDP messages on '%s'", subscribers_["cam"]->getTopic().c_str(), publisher_udp_->getTopic().c_str());
  ROS_LOG(INFO, "Converting UDP messages of type '%s' on '%s' to native ROS messages on '%s'", etsi_type_.c_str(), subscriber_udp_->getTopic().c_str(), publishers_["denm"]->getTopic().c_str());
  ROS_LOG(INFO, "Converting native ROS DENMs on '%s' to UDP messages on '%s'", subscribers_["denm"]->getTopic().c_str(), publisher_udp_->getTopic().c_str());
  ROS_LOG(INFO, "Converting UDP messages of type '%s' on '%s' to native ROS messages on '%s'", etsi_type_.c_str(), subscriber_udp_->getTopic().c_str(), publishers_["spatem"]->getTopic().c_str());
  ROS_LOG(INFO, "Converting native ROS SPATEMs on '%s' to UDP messages on '%s'", subscribers_["spatem"]->getTopic().c_str(), publisher_udp_->getTopic().c_str());
  ROS_LOG(INFO, "Converting UDP messages of type '%s' on '%s' to native ROS messages on '%s'", etsi_type_.c_str(), subscriber_udp_->getTopic().c_str(), publishers_["mapem"]->getTopic().c_str());
  ROS_LOG(INFO, "Converting native ROS MAPEMs on '%s' to UDP messages on '%s'", subscribers_["mapem"]->getTopic().c_str(), publisher_udp_->getTopic().c_str());
#else
  publisher_udp_ = this->create_publisher<UdpPacket>(kOutputTopicUdp, 1);
  publisher_cam_ = this->create_publisher<cam_msgs::CAM>(kOutputTopicCam, 1);
  publisher_denm_ = this->create_publisher<denm_msgs::DENM>(kOutputTopicDenm, 1);
  publisher_spatem_ = this->create_publisher<spatem_msgs::SPATEM>(kOutputTopicSpatem, 1);
  publisher_mapem_ = this->create_publisher<mapem_msgs::MAPEM>(kOutputTopicMapem, 1);
  subscriber_udp_ = this->create_subscription<UdpPacket>(kInputTopicUdp, 1, std::bind(&Converter::udpCallback, this, std::placeholders::_1));
  subscribers_["cam"] = this->create_subscription<cam_msgs::CAM>(kInputTopicCam, 1, std::bind(&Converter::rosCallbackCam, this, std::placeholders::_1));
  subscribers_["denm"] = this->create_subscription<denm_msgs::DENM>(kInputTopicDenm, 1, std::bind(&Converter::rosCallbackDenm, this, std::placeholders::_1));
  subscribers_["spatem"] = this->create_subscription<spatem_msgs::SPATEM>(kInputTopicSpatem, 1, std::bind(&Converter::rosCallbackSpatem, this, std::placeholders::_1));
  subscribers_["mapem"] = this->create_subscription<mapem_msgs::MAPEM>(kInputTopicMapem, 1, std::bind(&Converter::rosCallbackMapem, this, std::placeholders::_1));
  ROS_LOG(INFO, "Converting UDP messages of type '%s' on '%s' to native ROS messages on '%s'", etsi_type_.c_str(), subscriber_udp_->get_topic_name(), publisher_cam_->get_topic_name());
  ROS_LOG(INFO, "Converting native ROS CAMs on '%s' to UDP messages on '%s'", subscribers_["cam"]->get_topic_name(), publisher_udp_->get_topic_name());
  ROS_LOG(INFO, "Converting UDP messages of type '%s' on '%s' to native ROS messages on '%s'", etsi_type_.c_str(), subscriber_udp_->get_topic_name(), publisher_denm_->get_topic_name());
  ROS_LOG(INFO, "Converting native ROS DENMs on '%s' to UDP messages on '%s'", subscribers_["denm"]->get_topic_name(), publisher_udp_->get_topic_name());
  ROS_LOG(INFO, "Converting UDP messages of type '%s' on '%s' to native ROS messages on '%s'", etsi_type_.c_str(), subscriber_udp_->get_topic_name(), publisher_spatem_->get_topic_name());
  ROS_LOG(INFO, "Converting native ROS SPATEMs on '%s' to UDP messages on '%s'", subscribers_["spatem"]->get_topic_name(), publisher_udp_->get_topic_name());
  ROS_LOG(INFO, "Converting UDP messages of type '%s' on '%s' to native ROS messages on '%s'", etsi_type_.c_str(), subscriber_udp_->get_topic_name(), publisher_mapem_->get_topic_name());
  ROS_LOG(INFO, "Converting native ROS MAPEMs on '%s' to UDP messages on '%s'", subscribers_["mapem"]->get_topic_name(), publisher_udp_->get_topic_name());
#endif
}


template <typename T_ros, typename T_struct>
T_struct Converter::rosMessageToStruct(const T_ros& msg, const asn_TYPE_descriptor_t* type_descriptor, std::function<void(const T_ros&, T_struct&)> conversion_fn) {

  T_struct asn1_struct;
  conversion_fn(msg, asn1_struct);
  if (logLevelIsDebug()) asn_fprint(stdout, type_descriptor, &asn1_struct);

  return asn1_struct;
}


template <typename T_struct>
bool Converter::encodeStructToBuffer(const T_struct& asn1_struct, const asn_TYPE_descriptor_t* type_descriptor, uint8_t* buffer, int& size) {

  char error_buffer[1024];
  size_t error_length = sizeof(error_buffer);
  int check_ret = asn_check_constraints(type_descriptor, &asn1_struct, error_buffer, &error_length);
  if (check_ret != 0) {
    ROS_LOG(ERROR, "Check of struct failed: %s", error_buffer);
    return false;
  }
  asn_encode_to_new_buffer_result_t ret = asn_encode_to_new_buffer(0, ATS_UNALIGNED_BASIC_PER, type_descriptor, &asn1_struct);
  if (ret.result.encoded == -1) {
    ROS_LOG(ERROR, "Failed to encode message: %s", ret.result.failed_type->xml_tag);
    return false;
  }

  buffer = static_cast<uint8_t*>(ret.buffer);
  size = ret.result.encoded;

  return true;
}


UdpPacket Converter::bufferToUdpPacketMessage(const uint8_t* buffer, const int size) {

#ifdef ROS1
  UdpPacket udp_msg;
#else
  UdpPacket udp_msg;
#endif
  if (etsi_type_ == "auto") {
    // add BTP-Header, if type detection is enabled
    uint16_t destination_port = htons(kBtpHeaderDestinationPortCam);
    uint16_t destination_port_info = 0;
    uint16_t* btp_header = new uint16_t[2] {destination_port, destination_port_info};
    uint8_t* btp_header_uint8 = reinterpret_cast<uint8_t*>(btp_header);
    udp_msg.data.insert(udp_msg.data.end(), btp_header_uint8, btp_header_uint8 + 2 * sizeof(uint16_t));
    delete[] btp_header;
  }
  udp_msg.data.insert(udp_msg.data.end(), buffer, buffer + size);

  return udp_msg;
}


template <typename T_ros, typename T_struct>
bool Converter::encodeRosMessageToUdpPacketMessage(const T_ros& msg, UdpPacket& udp_msg, const asn_TYPE_descriptor_t* type_descriptor, std::function<void(const T_ros&, T_struct&)> conversion_fn) {

  // convert ROS msg to struct
  auto asn1_struct = this->rosMessageToStruct(msg, type_descriptor, conversion_fn);

  // encode struct to ASN1 bitstring
  uint8_t* buffer;
  int buffer_size;
  bool successful = this->encodeStructToBuffer(asn1_struct, type_descriptor, buffer, buffer_size);
  if (!successful) return false;

  // copy bitstring to ROS UDP msg
  udp_msg = this->bufferToUdpPacketMessage(buffer, buffer_size);

  return true;
}


#ifdef ROS1
void Converter::udpCallback(const UdpPacket::ConstPtr udp_msg) {
#else
void Converter::udpCallback(const UdpPacket::UniquePtr udp_msg) {
#endif

  ROS_LOG(DEBUG, "Received bitstring");

  // decode BTP-Header, if type detection is enabled
  std::string detected_etsi_type = etsi_type_;
  int offset = 0;
  if (etsi_type_ == "auto") {
    offset = 4;
    const uint16_t* btp_header = reinterpret_cast<const uint16_t*>(&udp_msg->data[0]);
    uint16_t destination_port = ntohs(btp_header[0]);
    if (destination_port == kBtpHeaderDestinationPortCam) detected_etsi_type = "cam";
    else if (destination_port == kBtpHeaderDestinationPortDenm) detected_etsi_type = "denm";
    else if (destination_port == kBtpHeaderDestinationPortMapem) detected_etsi_type = "mapem";
    else if (destination_port == kBtpHeaderDestinationPortSpatem) detected_etsi_type = "spatem";
    else if (destination_port == kBtpHeaderDestinationPortMapem) detected_etsi_type = "mapem";
    else if (destination_port == kBtpHeaderDestinationPortIvi) detected_etsi_type = "ivi";
    else if (destination_port == kBtpHeaderDestinationPortCpm) detected_etsi_type = "cpm";
    else detected_etsi_type = "unknown";
  }

  if (detected_etsi_type == "cam") {

    // decode ASN1 bitstring to struct
    CAM_t* asn1_struct = nullptr;
    asn_dec_rval_t ret = asn_decode(0, ATS_UNALIGNED_BASIC_PER, &asn_DEF_CAM, (void **)&asn1_struct, &udp_msg->data[offset], udp_msg->data.size() - offset);
    if (ret.code != RC_OK) {
      ROS_LOG(ERROR, "Failed to decode message");
      return;
    }
    if (logLevelIsDebug()) asn_fprint(stdout, &asn_DEF_CAM, asn1_struct);

    // convert struct to ROS msg and publish
    cam_msgs::CAM msg;
    etsi_its_cam_conversion::toRos_CAM(*asn1_struct, msg);

    // publish msg
#ifdef ROS1
    publishers_["cam"]->publish(msg);
#else
    publisher_cam_->publish(msg);
#endif
    ROS_LOG(DEBUG, "Published CAM");

  } else if (detected_etsi_type == "denm") {

    // decode ASN1 bitstring to struct
    DENM_t* asn1_struct = nullptr;
    asn_dec_rval_t ret = asn_decode(0, ATS_UNALIGNED_BASIC_PER, &asn_DEF_DENM, (void **)&asn1_struct, &udp_msg->data[offset], udp_msg->data.size() - offset);
    if (ret.code != RC_OK) {
      ROS_LOG(ERROR, "Failed to decode message");
      return;
    }
    if (logLevelIsDebug()) asn_fprint(stdout, &asn_DEF_DENM, asn1_struct);

    // convert struct to ROS msg and publish
    denm_msgs::DENM msg;
    etsi_its_denm_conversion::toRos_DENM(*asn1_struct, msg);

    // publish msg
#ifdef ROS1
    publishers_["denm"]->publish(msg);
#else
    publisher_denm_->publish(msg);
#endif
    ROS_LOG(DEBUG, "Published DENM");

  } else if (detected_etsi_type == "spatem") {

    // decode ASN1 bitstring to struct
    SPATEM_t* asn1_struct = nullptr;
    asn_dec_rval_t ret = asn_decode(0, ATS_UNALIGNED_BASIC_PER, &asn_DEF_SPATEM, (void **)&asn1_struct, &udp_msg->data[offset], udp_msg->data.size() - offset);
    if (ret.code != RC_OK) {
      ROS_LOG(ERROR, "Failed to decode message");
      return;
    }
    if (logLevelIsDebug()) asn_fprint(stdout, &asn_DEF_SPATEM, asn1_struct);

    // convert struct to ROS msg and publish
    spatem_msgs::SPATEM msg;
    etsi_its_spatem_conversion::toRos_SPATEM(*asn1_struct, msg);

    // publish msg
#ifdef ROS1
    publishers_["spatem"]->publish(msg);
#else
    publisher_spatem_->publish(msg);
#endif
    ROS_LOG(DEBUG, "Published SPATEM");

  } else if (detected_etsi_type == "mapem") {

    // decode ASN1 bitstring to struct
    MAPEM_t* asn1_struct = nullptr;
    asn_dec_rval_t ret = asn_decode(0, ATS_UNALIGNED_BASIC_PER, &asn_DEF_MAPEM, (void **)&asn1_struct, &udp_msg->data[offset], udp_msg->data.size() - offset);
    if (ret.code != RC_OK) {
      ROS_LOG(ERROR, "Failed to decode message");
      return;
    }
    if (logLevelIsDebug()) asn_fprint(stdout, &asn_DEF_MAPEM, asn1_struct);

    // convert struct to ROS msg and publish
    mapem_msgs::MAPEM msg;
    etsi_its_mapem_conversion::toRos_MAPEM(*asn1_struct, msg);

    // publish msg
#ifdef ROS1
    publishers_["mapem"]->publish(msg);
#else
    publisher_mapem_->publish(msg);
#endif
    ROS_LOG(DEBUG, "Published MAPEM");

  } else {
    ROS_LOG(ERROR, "Detected ETSI message type '%s' not yet supported, dropping message", detected_etsi_type.c_str());
    return;
  }
}


#ifdef ROS1
void Converter::rosCallbackCam(const cam_msgs::CAM::ConstPtr msg) {
#else
void Converter::rosCallbackCam(const cam_msgs::CAM::UniquePtr msg) {
#endif

  ROS_LOG(DEBUG, "Received CAM");

  // encode ROS msg to UDP msg
  UdpPacket udp_msg;
  bool success = this->encodeRosMessageToUdpPacketMessage(*msg, udp_msg, &asn_DEF_CAM, std::function<void(const cam_msgs::CAM&, CAM_t&)>(etsi_its_cam_conversion::toStruct_CAM));
  if (!success) return;

  // publish UDP msg
  publisher_udp_->publish(udp_msg);
  ROS_LOG(DEBUG, "Published CAM bitstring");
}


#ifdef ROS1
void Converter::rosCallbackDenm(const denm_msgs::DENM::ConstPtr msg) {
#else
void Converter::rosCallbackDenm(const denm_msgs::DENM::UniquePtr msg) {
#endif

  ROS_LOG(DEBUG, "Received DENM");

  // encode ROS msg to UDP msg
  UdpPacket udp_msg;
  bool success = this->encodeRosMessageToUdpPacketMessage(*msg, udp_msg, &asn_DEF_DENM, std::function<void(const denm_msgs::DENM&, DENM_t&)>(etsi_its_denm_conversion::toStruct_DENM));
  if (!success) return;

  // publish UDP msg
  publisher_udp_->publish(udp_msg);
  ROS_LOG(DEBUG, "Published DENM bitstring");
}


#ifdef ROS1
void Converter::rosCallbackSpatem(const spatem_msgs::SPATEM::ConstPtr msg) {
#else
void Converter::rosCallbackSpatem(const spatem_msgs::SPATEM::UniquePtr msg) {
#endif

  ROS_LOG(DEBUG, "Received SPATEM");

  // encode ROS msg to UDP msg
  UdpPacket udp_msg;
  bool success = this->encodeRosMessageToUdpPacketMessage(*msg, udp_msg, &asn_DEF_SPATEM, std::function<void(const spatem_msgs::SPATEM&, SPATEM_t&)>(etsi_its_spatem_conversion::toStruct_SPATEM));
  if (!success) return;

  // publish UDP msg
  publisher_udp_->publish(udp_msg);
  ROS_LOG(DEBUG, "Published SPATEM bitstring");
}


#ifdef ROS1
void Converter::rosCallbackMapem(const mapem_msgs::MAPEM::ConstPtr msg) {
#else
void Converter::rosCallbackMapem(const mapem_msgs::MAPEM::UniquePtr msg) {
#endif

  ROS_LOG(DEBUG, "Received MAPEM");

  // encode ROS msg to UDP msg
  UdpPacket udp_msg;
  bool success = this->encodeRosMessageToUdpPacketMessage(*msg, udp_msg, &asn_DEF_MAPEM, std::function<void(const mapem_msgs::MAPEM&, MAPEM_t&)>(etsi_its_mapem_conversion::toStruct_MAPEM));
  if (!success) return;

  // publish UDP msg
  publisher_udp_->publish(udp_msg);
  ROS_LOG(DEBUG, "Published MAPEM bitstring");
}


}  // end of namespace
