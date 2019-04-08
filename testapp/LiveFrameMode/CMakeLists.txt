cmake_minimum_required(VERSION 2.4.7)
PROJECT(QHYXXXDEMO)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../../cmake_modules/")

find_package(USB-1 REQUIRED)
include_directories($(USB_1_INCLUDE_DIR))

find_package(OpenCV REQUIRED) # locate OpenCV in system
include_directories(${OpenCV_INCLUDE_DIRS}) # provide library headers
message("OpenCV_LIBS: " ${OpenCV_LIBS})  #display opencv libs found

#include_directories($(USB_1_INCLUDE_DIR))
#include_directories($(OpenCV_INCLUDE_DIR))
include_directories("/usr/local/include/")
link_directories("/usr/local/lib/")
aux_source_directory(. SRC_LIST)

foreach(F ${SRC_LIST})
    string(LENGTH ${F} NAMELENGTH)
    string(SUBSTRING ${F} 0 ${NAMELENGTH} FILENAME)
    string(REPLACE .cpp test FILENAME1 ${FILENAME})
    message(FILENAME1 is ${F})
    add_executable(${FILENAME1} ${F})
    target_link_libraries(${FILENAME1} -lqhyccd ${LIBUSB_1_LIBRARIES})
    target_link_libraries(${FILENAME1} ${OpenCV_LIBS})
endforeach(F)
