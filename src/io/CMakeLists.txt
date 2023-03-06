# Add sources
target_sources(${PROJECT_NAME}
               PRIVATE
			   ${CMAKE_CURRENT_SOURCE_DIR}/base.h
               ${CMAKE_CURRENT_SOURCE_DIR}/base.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/read_laser.h
               ${CMAKE_CURRENT_SOURCE_DIR}/read_laser.cpp
			   ${CMAKE_CURRENT_SOURCE_DIR}/read_camera.h
               ${CMAKE_CURRENT_SOURCE_DIR}/read_camera.cpp
			   ${CMAKE_CURRENT_SOURCE_DIR}/pcap_parse.h
               ${CMAKE_CURRENT_SOURCE_DIR}/pcap_parse.cpp)

# Install headers

#install(FILES ${CAMERA}
#        DESTINATION ${MYSLAM_INCLUDE_INSTALL_DIR}/match)


