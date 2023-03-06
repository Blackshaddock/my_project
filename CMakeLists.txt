cmake_minimum_required(VERSION 3.1)
project(myslam LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(3RDPART_ROOT ${CMAKE_CURRENT_LIST_DIR}/GeneralLibs/)
find_package(3rdparty REQUIRED HINTS ${3RDPART_ROOT})


message(STATUS "Use OpenCV ${OpenCV_VERSION}")





add_subdirectory(src)

set(BUILD_EXAMPLES ON CACHE BOOL "Build examples")
if(BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

set(BUILD_TESTS OFF CACHE BOOL "Build tests")
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
