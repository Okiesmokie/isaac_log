cmake_minimum_required(VERSION 3.2.2)
project(IsaacLog)

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" _insource)
if (_insource)
  message(SEND_ERROR "In-source builds are not allowed.  Please run cmake from the bin/ directory.")
  message(FATAL_ERROR "Remove the file CMakeCache.txt in ${CMAKE_SOURCE_DIR} first.")
endif (_insource)

include_directories("include")

add_subdirectory(lib)
add_subdirectory(examples)
