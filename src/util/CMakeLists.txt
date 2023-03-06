# Add sources
target_sources(${PROJECT_NAME}
               PRIVATE
               ${CMAKE_CURRENT_SOURCE_DIR}/string_util.h
               ${CMAKE_CURRENT_SOURCE_DIR}/string_util.cpp)
			   #${CMAKE_CURRENT_SOURCE_DIR}/hesai_util.h
               #${CMAKE_CURRENT_SOURCE_DIR}/hesai_util.cpp)

# Install headers

#install(FILES ${CAMERA}
#        DESTINATION ${MYSLAM_INCLUDE_INSTALL_DIR}/match)


