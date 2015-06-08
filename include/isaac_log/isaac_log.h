// Copyright (c) 2015, Steven Shewfelt.
// All rights reserved.
#ifndef ISAAC_LOG_ISAAC_LOG_H_
#define ISAAC_LOG_ISAAC_LOG_H_

#include <functional>
#include <string>
#include <atomic>
#include <thread>  // NOLINT(build/c++11)

namespace isaac_log {

class IsaacLog {
 public:
  IsaacLog();
  ~IsaacLog();

  // Sets and checks the filename of the log
  // Returns true if the log was found.
  // If it returns false, the error message is
  // stored in `last_error_message_`
  bool set_log_filename(std::string log_filename);

  // Begins reading the log file and calls the
  // callback functions during appropriate times.
  // NOTE: This creates a new thread.
  // Returns true if the thread was started
  // If it returns false, the error message is
  // stored in `last_error_message_`
  bool BeginReading();

  bool TerminateThread() { terminate_thread_ = true; }

  // Callback setting methods
  void set_item_pickup_callback(
      std::function<void()> item_pickup_callback) {
    item_pickup_callback_ = item_pickup_callback;
  }

  void set_boss_encounter_callback(
      std::function<void()> boss_encounter_callback) {
    boss_encounter_callback_ = boss_encounter_callback;
  }
  // End callback setting methods

 private:
  std::string last_error_message_;

  std::function<void()> item_pickup_callback_;
  std::function<void()> boss_encounter_callback_;

  std::string log_filename_;

  std::atomic<bool> thread_running_;
  std::atomic<bool> terminate_thread_;
  std::thread reading_thread_;

  void ReadingThread();
};

}  // namespace isaac_log

#endif  // ISAAC_LOG_ISAAC_LOG_H_
