# CMakeList.txt : CMake project for one-time-pad, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 11)

project ("one-time-pad")

# Add source to this project's executable.
add_executable (one-time-pad "one-time-pad.cpp" "one-time-pad.h"  "key.h" )

# TODO: Add tests and install targets if needed.
