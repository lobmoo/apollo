/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "cyber/transport/rtps/participant.h"

#include "cyber/proto/transport_conf.pb.h"
#include "cyber/common/global_data.h"
#include "cyber/common/log.h"

namespace apollo {
namespace cyber {
namespace transport {

Participant::Participant(const std::string& name, int send_port,
                         eprosima::fastdds::dds::DomainParticipantListener* listener)
    : shutdown_(false),
      name_(name),
      send_port_(send_port),
      listener_(listener),
      fastrtps_participant_(nullptr) {}

Participant::~Participant() {}

void Participant::Shutdown() {
  if (shutdown_.exchange(true)) {
    return;
  }

  std::lock_guard<std::mutex> lk(mutex_);
  if (fastrtps_participant_ != nullptr) {
    eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(fastrtps_participant_);
    fastrtps_participant_ = nullptr;
    listener_ = nullptr;
  }
}

eprosima::fastdds::dds::DomainParticipant* Participant::fastrtps_participant() {
  if (shutdown_.load()) {
    return nullptr;
  }

  std::lock_guard<std::mutex> lk(mutex_);
  if (fastrtps_participant_ != nullptr) {
    return fastrtps_participant_;
  }

  CreateFastRtpsParticipant(name_, send_port_, listener_);
  return fastrtps_participant_;
}

void Participant::CreateFastRtpsParticipant(
    const std::string& name, int send_port,
    eprosima::fastdds::dds::DomainParticipantListener* listener) {
  //uint32_t domain_id = 80;

  // const char* val = ::getenv("CYBER_DOMAIN_ID");
  // if (val != nullptr) {
  //   try {
  //     domain_id = std::stoi(val);
  //   } catch (const std::exception& e) {
  //     AERROR << "convert domain_id error " << e.what();
  //     return;
  //   }
  // }

  // auto part_attr_conf = std::make_shared<proto::RtpsParticipantAttr>();
  // auto& global_conf = common::GlobalData::Instance()->Config();
  // if (global_conf.has_transport_conf() &&
  //     global_conf.transport_conf().has_participant_attr()) {
  //   part_attr_conf->CopyFrom(global_conf.transport_conf().participant_attr());
  // }

  // std::string ip_env("127.0.0.1");
  // const char* ip_val = ::getenv("CYBER_IP");
  // if (ip_val != nullptr) {
  //   ip_env = ip_val;
  //   if (ip_env.empty()) {
  //     AERROR << "invalid CYBER_IP (an empty string)";
  //     return;
  //   }
  // }
  // ADEBUG << "cyber ip: " << ip_env;

  eprosima::fastdds::dds::DomainParticipantQos pqos;
  pqos.name(name);
  fastrtps_participant_ = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, pqos, listener);
  RETURN_IF_NULL(fastrtps_participant_);
  type_.register_type(fastrtps_participant_);
}

}  // namespace transport
}  // namespace cyber
}  // namespace apollo
