cmake_minimum_required(VERSION 2.8)
project(Soil)

if(MSVC)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/bin")
elseif(MSVC)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
endif(MSVC)

include_directories(include)
file(GLOB HEADER_FILES include/*.h)

include_directories(src)
file(GLOB LIB_FILES src/*.cpp)

add_library(soil SHARED ${LIB_FILES} ${HEADER_FILES})
set_target_properties(soil PROPERTIES PREFIX "")
