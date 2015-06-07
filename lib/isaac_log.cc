// Copyright (c) 2015, Steven Shewfelt.
// All rights reserved.
#include <isaac_log/isaac_log.h>
#include <isaac_log/error_messages.h>
#include <cstdio>
#include <thread>  // NOLINT(build/c++11)

namespace isaac_log {

void MyCallbackFunction() {
  printf("Some Callback\n");
}

IsaacLog::IsaacLog() :
    last_error_message_(""),
    log_filename_(""),
    thread_running_(false) {
}

IsaacLog::~IsaacLog() {
  // End the thread
  if (thread_running_) {
    reading_thread_.join();
  }
}

bool IsaacLog::set_log_filename(std::string log_filename) {
  if (thread_running_) {
    // Filename should not be changed after the thread has started
    last_error_message_ = kErrorMessages["thread_running"];
    return false;
  }

  log_filename_ = log_filename;

  // TODO(Steven): Add checks to ensure the log exists

  return true;
}

bool IsaacLog::BeginReading() {
  // TODO(Steven): Add error checking and set `last_error_message_`
  //               if appropriate.

  if (thread_running_) {
    last_error_message_ = kErrorMessages["thread_running"];
    return false;
  }

  reading_thread_ = std::thread(&IsaacLog::ReadingThread, this);

  return true;
}

void IsaacLog::ReadingThread() {
  thread_running_ = true;

  item_pickup_callback_();

  thread_running_ = false;
}

}  // namespace isaac_log
