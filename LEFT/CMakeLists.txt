cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0074 NEW)    # respect <PACKAGE>_ROOT variables in "find_package"
include(CMakePrintHelpers)

project(PylonSamples VERSION 0.0)
find_package(pylon)

add_executable( LEFTSample
  LEFTSample.cpp
)
target_link_libraries( LEFTSample PRIVATE pylon::pylon )
install( TARGETS LEFTSample )