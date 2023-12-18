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

#pragma once

#include "etsi_its_mapem_msgs/msg/mapem.hpp"
#include "etsi_its_spatem_msgs/msg/spatem.hpp"

#include "displays/MAPEM/mapem_render_object.hpp"

#include "rviz_common/ros_topic_display.hpp"
#include "rviz_rendering/objects/movable_text.hpp"
#include "rviz_rendering/objects/shape.hpp"

#include <rclcpp/rclcpp.hpp>

namespace Ogre
{
class ManualObject;
}

namespace rviz_common
{
namespace properties
{
  class ColorProperty;
  class FloatProperty;
  class TopicProperty;
}  // namespace properties
}  // namespace rviz_common

namespace etsi_its_msgs
{
namespace displays
{

/**
 * @class MAPEMDisplay
 * @brief Displays an etsi_its_mapem_msgs::MAPEM
 */
class MAPEMDisplay : public
  rviz_common::RosTopicDisplay<etsi_its_mapem_msgs::msg::MAPEM>
{
  Q_OBJECT

public:
  MAPEMDisplay();
  ~MAPEMDisplay() override;

  void onInitialize() override;

  void reset() override;

protected:
  void processMessage(etsi_its_mapem_msgs::msg::MAPEM::ConstSharedPtr msg) override;
  void update(float wall_dt, float ros_dt) override;

  Ogre::ManualObject *manual_object_;

  rclcpp::Node::SharedPtr rviz_node_;

  // Properties
  rviz_common::properties::BoolProperty *show_meta_, *show_station_id_, *show_speed_;
  rviz_common::properties::FloatProperty *buffer_timeout_, *bb_scale_, *char_height_;
  rviz_common::properties::ColorProperty *color_property_, *text_color_property_;
  rviz_common::properties::TopicProperty *spatem_topic_property_;

  std::unordered_map<int, MAPEMRenderObject> mapems_;
  // std::unordered_map<int, SPATEMRenderObject> spatems_;
  std::vector<std::shared_ptr<rviz_rendering::Shape>> bboxs_;
  std::vector<std::shared_ptr<rviz_rendering::MovableText>> texts_;
};

}  // namespace displays
}  // namespace etsi_its_msgs