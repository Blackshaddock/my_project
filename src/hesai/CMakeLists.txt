# Add sources
target_sources(${PROJECT_NAME}
               PRIVATE
			   ${CMAKE_CURRENT_SOURCE_DIR}/PandarPacket.h
               ${CMAKE_CURRENT_SOURCE_DIR}/PandarScan.h
               ${CMAKE_CURRENT_SOURCE_DIR}/pandarQT.h
			   ${CMAKE_CURRENT_SOURCE_DIR}/pandarXT.h
               ${CMAKE_CURRENT_SOURCE_DIR}/point_types.h
			   ${CMAKE_CURRENT_SOURCE_DIR}/pandarGeneral_internal.h
               ${CMAKE_CURRENT_SOURCE_DIR}/pandarGeneral_internal.cpp)

# Install headers

#install(FILES ${CAMERA}
#        DESTINATION ${MYSLAM_INCLUDE_INSTALL_DIR}/match)


