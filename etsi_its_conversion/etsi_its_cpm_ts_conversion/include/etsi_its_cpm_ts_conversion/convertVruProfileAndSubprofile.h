/** ============================================================================
MIT License

Copyright (c) 2023-2024 Institute for Automotive Engineering (ika), RWTH Aachen University

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

#include <etsi_its_cpm_ts_coding/cpm_ts_VruProfileAndSubprofile.h>
#include <etsi_its_cpm_ts_conversion/convertVruSubProfileAnimal.h>
#include <etsi_its_cpm_ts_conversion/convertVruSubProfileBicyclist.h>
#include <etsi_its_cpm_ts_conversion/convertVruSubProfileMotorcyclist.h>
#include <etsi_its_cpm_ts_conversion/convertVruSubProfilePedestrian.h>
#ifdef ROS1
#include <etsi_its_cpm_ts_msgs/VruProfileAndSubprofile.h>
namespace cpm_ts_msgs = etsi_its_cpm_ts_msgs;
#else
#include <etsi_its_cpm_ts_msgs/msg/vru_profile_and_subprofile.hpp>
namespace cpm_ts_msgs = etsi_its_cpm_ts_msgs::msg;
#endif


namespace etsi_its_cpm_ts_conversion {

void toRos_VruProfileAndSubprofile(const cpm_ts_VruProfileAndSubprofile_t& in, cpm_ts_msgs::VruProfileAndSubprofile& out) {
  switch (in.present) {
  case cpm_ts_VruProfileAndSubprofile_PR_pedestrian:
    toRos_VruSubProfilePedestrian(in.choice.pedestrian, out.pedestrian);
    out.choice = cpm_ts_msgs::VruProfileAndSubprofile::CHOICE_PEDESTRIAN;
    break;
  case cpm_ts_VruProfileAndSubprofile_PR_bicyclistAndLightVruVehicle:
    toRos_VruSubProfileBicyclist(in.choice.bicyclistAndLightVruVehicle, out.bicyclist_and_light_vru_vehicle);
    out.choice = cpm_ts_msgs::VruProfileAndSubprofile::CHOICE_BICYCLIST_AND_LIGHT_VRU_VEHICLE;
    break;
  case cpm_ts_VruProfileAndSubprofile_PR_motorcyclist:
    toRos_VruSubProfileMotorcyclist(in.choice.motorcyclist, out.motorcyclist);
    out.choice = cpm_ts_msgs::VruProfileAndSubprofile::CHOICE_MOTORCYCLIST;
    break;
  case cpm_ts_VruProfileAndSubprofile_PR_animal:
    toRos_VruSubProfileAnimal(in.choice.animal, out.animal);
    out.choice = cpm_ts_msgs::VruProfileAndSubprofile::CHOICE_ANIMAL;
    break;
  default: break;
  }
}

void toStruct_VruProfileAndSubprofile(const cpm_ts_msgs::VruProfileAndSubprofile& in, cpm_ts_VruProfileAndSubprofile_t& out) {
  memset(&out, 0, sizeof(cpm_ts_VruProfileAndSubprofile_t));

  switch (in.choice) {
  case cpm_ts_msgs::VruProfileAndSubprofile::CHOICE_PEDESTRIAN:
    toStruct_VruSubProfilePedestrian(in.pedestrian, out.choice.pedestrian);
    out.present = cpm_ts_VruProfileAndSubprofile_PR::cpm_ts_VruProfileAndSubprofile_PR_pedestrian;
    break;
  case cpm_ts_msgs::VruProfileAndSubprofile::CHOICE_BICYCLIST_AND_LIGHT_VRU_VEHICLE:
    toStruct_VruSubProfileBicyclist(in.bicyclist_and_light_vru_vehicle, out.choice.bicyclistAndLightVruVehicle);
    out.present = cpm_ts_VruProfileAndSubprofile_PR::cpm_ts_VruProfileAndSubprofile_PR_bicyclistAndLightVruVehicle;
    break;
  case cpm_ts_msgs::VruProfileAndSubprofile::CHOICE_MOTORCYCLIST:
    toStruct_VruSubProfileMotorcyclist(in.motorcyclist, out.choice.motorcyclist);
    out.present = cpm_ts_VruProfileAndSubprofile_PR::cpm_ts_VruProfileAndSubprofile_PR_motorcyclist;
    break;
  case cpm_ts_msgs::VruProfileAndSubprofile::CHOICE_ANIMAL:
    toStruct_VruSubProfileAnimal(in.animal, out.choice.animal);
    out.present = cpm_ts_VruProfileAndSubprofile_PR::cpm_ts_VruProfileAndSubprofile_PR_animal;
    break;
  default: break;
  }
}

}
