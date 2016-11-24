cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
project (Main)

# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 1)
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "src/cmake.h.in"
  "../src/cmake.h"
)

################################
# 3rdparty
################################
ADD_SUBDIRECTORY (3rdparty)

# Enable ExternalProject CMake module
include(ExternalProject)

# Set the build type if it isn't already
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/3rdparty)

# Add gtest
ExternalProject_Add(
    googletest
	DOWNLOAD_COMMAND ""
	SOURCE_DIR "../3rdparty/googletest/"
    TIMEOUT 10
    # Force separate output paths for debug and release builds to allow easy
    # identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -Dgtest_force_shared_crt=ON
    # Disable install step
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
include_directories(${source_dir}/googlemock/include)
include_directories(${source_dir}/googletest/include)
include_directories(${source_dir}/googlemock)
include_directories(${source_dir}/googletest)
include_directories("${CMAKE_SOURCE_DIR}/src"
	"${CMAKE_SOURCE_DIR}/src/test")

file(GLOB SOURCES
    src/mult.h
    src/mult.cpp
)

add_library(MainFiles ${SOURCES})

# Add test executable target
add_executable(MainTest ${PROJECT_SOURCE_DIR}/src/test/main.cpp)

# add the executable
add_executable(Main src/main.cpp)

# Create dependency of MainTest on googletest
add_dependencies(MainTest googletest)

# Specify MainTest's link libraries
ExternalProject_Get_Property(googletest binary_dir)
if(MSVC)
  set(Suffix ".lib")
else()
  set(Suffix ".a")
  set(Pthread "-pthread")
endif()

target_link_libraries(
    Main
	MainFiles)

target_link_libraries(
    MainTest
	MainFiles
    debug ${binary_dir}/googlemock/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${Suffix}
    optimized ${binary_dir}/googlemock/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${Suffix}
    ${Pthread})