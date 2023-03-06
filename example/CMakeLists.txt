# ----- Find dependencies -----

set(3RDPART_ROOT ${CMAKE_CURRENT_LIST_DIR}/GeneralLibs/)
find_package(3rdparty REQUIRED HINTS ${3RDPART_ROOT})

# ----- Build example executables -----

set(EXECUTABLE_TARGETS "")
include_directories(${PROJECT_SOURCE_DIR}/src/)
link_libraries(${PROJECT_NAME})

add_executable(run_camera_slam run_camera_slam.cc)
list(APPEND EXECUTABLE_TARGETS run_camera_slam)

add_executable(run_pcap_hesai run_pcap_hesai.cc)
list(APPEND EXECUTABLE_TARGETS run_pcap_hesai)

foreach(EXECUTABLE_TARGET IN LISTS EXECUTABLE_TARGETS)
    # Set output directory for executables  
    # Link OpenVSLAM
    target_link_libraries(${EXECUTABLE_TARGET}                          
                          ${PROJECT_NAME}                         
                          )

endforeach()
