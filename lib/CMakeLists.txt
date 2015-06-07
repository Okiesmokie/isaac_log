set(ISAAC_LOG_SOURCES
  isaac_log.cc)

set(ISAAC_LOG_HEADERS
  ../include/isaac_log/isaac_log.h)

add_library(isaac_log ${ISAAC_LOG_SOURCES} ${ISAAC_LOG_HEADERS})

set_target_properties(isaac_log
  PROPERTIES
  CXX_STANDARD             11
  CXX_STANDARD_REQUIRED    ON
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/bin"
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release/lib")