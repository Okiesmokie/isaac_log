// Copyright (c) 2015, Steven Shewfelt.
// All rights reserved.
#ifndef ISAAC_LOG_ERROR_MESSAGES_H_
#define ISAAC_LOG_ERROR_MESSAGES_H_

#include <string>
#include <map>

namespace isaac_log {

static std::map<std::string, std::string> kErrorMessages = {
  { "thread_running", "Cannot perform this operation " \
                      "when the thread is running" }
};

}  // namespace isaac_log

#endif  // ISAAC_LOG_ERROR_MESSAGES_H_
