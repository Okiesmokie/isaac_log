set(CLI_EXAMPLE_SOURCES
  main.cc)

find_package(Threads)

add_executable(cli_example ${CLI_EXAMPLE_SOURCES})

target_link_libraries(cli_example isaac_log ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(cli_example
  PROPERTIES
  CXX_STANDARD             11
  CXX_STANDARD_REQUIRED    ON
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/bin/examples/cli"
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/lib/examples/cli"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/lib/examples/cli")
