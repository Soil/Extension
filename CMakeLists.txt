cmake_minimum_required(VERSION 3.0)
project(Soil)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

include_directories(include)
file(GLOB HEADER_FILES include/*.h)

include_directories(src)
file(GLOB LIB_FILES src/*.cpp)

add_library(soil SHARED ${LIB_FILES} ${HEADER_FILES})
set_target_properties(soil PROPERTIES PREFIX "")
