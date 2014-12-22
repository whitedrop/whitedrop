#/*
#-----------------------------------------------------------------------------
#Filename:    CMakeLists.txt
#-----------------------------------------------------------------------------
#
#This source file is part of the
#   ___                 __    __ _ _    _ 
#  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
# //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
#/ \_// (_| | | |  __/  \  /\  /| |   <| |
#\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
#      |___/                              
#      Tutorial Framework
#      http://www.ogre3d.org/tikiwiki/
#-----------------------------------------------------------------------------
#*/
cmake_minimum_required(VERSION 2.6)
 
project(Whitedrop)

set(DIR_TO_INCLUDE)
add_subdirectory(../engine/ engine)
add_subdirectory(./parser/ parser)
set(SRCS
	${SRCS}
	main.cpp
)
include_directories(${DIR_TO_INCLUDE})

add_executable(Whitedrop WIN32 ${HDRS} ${SRCS})
 
set_target_properties(Whitedrop PROPERTIES DEBUG_POSTFIX _d)
set(Boost_LIBRARIES "C:/OgreSDK/boost/lib/libboost_system-vc120-mt-gd-1_55.lib")
MESSAGE(STATUS "Boost_LIBRARIES=${Boost_LIBRARIES}")
MESSAGE(STATUS ${OGRE_Overlay_LIBRARIES})

target_link_libraries(Whitedrop ${TARGET_LIBRARIES})
 
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/bin)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/media)
 
# post-build copy for win32
if(WIN32 AND NOT MINGW)
	add_custom_command( TARGET Whitedrop PRE_BUILD
		COMMAND if not exist .\\dist\\bin mkdir .\\dist\\bin )
	add_custom_command( TARGET Whitedrop POST_BUILD
		COMMAND copy \"$(TargetPath)\" .\\dist\\bin )
endif(WIN32 AND NOT MINGW)

if(MINGW OR UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dist/bin)
endif(MINGW OR UNIX)
 
if(WIN32)
 
	install(TARGETS Whitedrop
		RUNTIME DESTINATION bin
		CONFIGURATIONS All)
 
	install(DIRECTORY ${CMAKE_SOURCE_DIR}/dist/Media
		DESTINATION ./
		CONFIGURATIONS Release RelWithDebInfo Debug
	)
 
	file(INSTALL ${CMAKE_SOURCE_DIR}/dist/bin/plugins.cfg
		${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
		DESTINATION dist/bin
	)
 
	file(INSTALL ${CMAKE_SOURCE_DIR}/dist/bin/plugins_d.cfg
		${CMAKE_SOURCE_DIR}/dist/bin/resources_d.cfg
		DESTINATION dist/bin
	)
 
   # as of sdk 1.7.2 we need to copy the boost dll's as well
   # because they're not linked statically (it worked with 1.7.1 though)
   install(FILES ${Boost_DATE_TIME_LIBRARY_RELEASE}
      ${Boost_THREAD_LIBRARY_RELEASE}
      DESTINATION bin
      CONFIGURATIONS Release RelWithDebInfo
   )
 
   install(FILES ${Boost_DATE_TIME_LIBRARY_DEBUG}
      ${Boost_THREAD_LIBRARY_DEBUG}
      DESTINATION bin
      CONFIGURATIONS Debug
   )
   # add_custom_command(TARGET Whitedrop PRE_BUILD
   #                 COMMAND ${CMAKE_COMMAND} -E copy_directory
   #                     ${CMAKE_SOURCE_DIR}/dist/media $<TARGET_FILE_DIR:Whitedrop>)
endif(WIN32)

if(UNIX)
 
	install(TARGETS Whitedrop
		RUNTIME DESTINATION bin
		CONFIGURATIONS All)
 
	install(DIRECTORY ${CMAKE_SOURCE_DIR}/dist/media
		DESTINATION ./
		CONFIGURATIONS Release RelWithDebInfo Debug
	)
 
	install(FILES ${CMAKE_SOURCE_DIR}/dist/bin/plugins.cfg
		${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
		DESTINATION bin
		CONFIGURATIONS Release RelWithDebInfo Debug
	)
 
endif(UNIX)
 
