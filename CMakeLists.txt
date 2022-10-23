cmake_minimum_required (VERSION 3.8)

project ("AttitudeEstimator")

add_executable (AttitudeEstimator "AttitudeEstimator.cpp" "AttitudeEstimator.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AttitudeEstimator PROPERTY CXX_STANDARD 20)
endif()