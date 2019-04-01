#===========================================================================
# Title      : CMakeLists.txt
# Note       : This cmake generates QHYCCD's shared library.
# Written by : Juan Bujjamer
# Version    : 1.0
# Date       : 6/2017
#===========================================================================
cmake_minimum_required(VERSION 2.6)
PROJECT(generate_so)
set (CMAKE_CXX_STANDARD 11)

message("PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../../cmake_modules/")
set(CMAKE_OSX_ARCHITECTURES i386)

find_package(USB-1 REQUIRED)
include_directories($(USB_1_INCLUDE_DIR))

find_package(OpenCV REQUIRED) # locate OpenCV in system
include_directories(${OpenCV_INCLUDE_DIRS}) # provide library headers
message("OpenCV_LIBS: " ${OpenCV_LIBS})  #display opencv libs found

include_directories("/usr/local/include/libusb-1.0")
link_directories("/usr/local/lib/")

add_executable(generate_so generate_so)
target_link_libraries(generate_so ${OpenCV_LIBS} -lqhyccd)
