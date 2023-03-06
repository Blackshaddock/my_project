# ----- Find dependencies -----






# Threads
find_package(Threads REQUIRED)



# Check BoW Framework


# ----- Create OpenVSLAM library -----



add_library(${PROJECT_NAME}
			STATIC
            ${CMAKE_CURRENT_SOURCE_DIR}/config.h
            )

file(GLOB Util  ${CMAKE_CURRENT_SOURCE_DIR}/util/*.h  ${CMAKE_CURRENT_SOURCE_DIR}/util/*.cpp )
source_group("util" FILES ${Util})

file(GLOB Io  ${CMAKE_CURRENT_SOURCE_DIR}/io/*.h  ${CMAKE_CURRENT_SOURCE_DIR}/io/*.cpp )
source_group("io" FILES ${Io})

file(GLOB Hesai  ${CMAKE_CURRENT_SOURCE_DIR}/hesai/*.h  ${CMAKE_CURRENT_SOURCE_DIR}/hesai/*.cpp )
source_group("hesai" FILES ${Hesai})

target_include_directories(${PROJECT_NAME}
						   PUBLIC
						   $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/>
							)
target_link_libraries(${PROJECT_NAME}
						${3RDPARTY_LIBRARIES}
)

# Install OpenVSLAM headers


# ----- Append subdirectory -----


add_subdirectory(util output)
add_subdirectory(io)
add_subdirectory(hesai)
