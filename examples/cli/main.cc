// Copyright (c) 2015, Steven Shewfelt.
// All rights reserved.
#include <isaac_log/isaac_log.h>
#include <cstdio>

void CallbackFunction() {
  ::printf("CallbackFunction() called\n");
}

int main(int argc, char *argv[]) {
  isaac_log::IsaacLog log_reader{};

  log_reader.set_log_filename("test.log");
  log_reader.set_item_pickup_callback(CallbackFunction);

  log_reader.BeginReading();

  while (true) {
    char c = ::getc(::stdin);

    if (c == 'q') {
      log_reader.TerminateThread();
      break;
    }
  }

  return 0;
}
