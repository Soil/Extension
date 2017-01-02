cmake_minimum_required(VERSION 3.0)
project(Soil)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

include_directories(include)
set(HEADER_FILES include/common.h)

include_directories(src)
add_library(soil SHARED src/main.cpp ${HEADER_FILES})
set_target_properties(soil PROPERTIES PREFIX "")
