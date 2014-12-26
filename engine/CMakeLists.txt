

if(WIN32)
	set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMAKE;$ENV{OGRE_HOME}/CMake/;${CMAKE_MODULE_PATH}")
	set(OGRE_SAMPLES_INCLUDEPATH
		$ENV{OGRE_HOME}/Samples/include
	)
endif(WIN32)

if(UNIX)
	if(EXISTS "/usr/local/lib/OGRE/cmake")

	  set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}" )
	  set(OGRE_SAMPLES_INCLUDEPATH "/usr/local/share/OGRE/samples/Common/include/" ) # We could just *assume* that developers uses this basepath : /usr/local

	elseif(EXISTS "/usr/lib/OGRE/cmake")

	  set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}" )
	  set(OGRE_SAMPLES_INCLUDEPATH "/usr/share/OGRE/samples/Common/include/" ) # Otherwise, this one

	else ()
	  message(SEND_ERROR "Failed to find module path.")
	endif(EXISTS "/usr/local/lib/OGRE")
endif(UNIX)
 
if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE PARENT_SCOPE)
endif ()
 
set(CMAKE_DEBUG_POSTFIX "_d" PARENT_SCOPE)
 
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist" PARENT_SCOPE)
 
find_package(OGRE REQUIRED)
 
#if(NOT "${OGRE_VERSION_NAME}" STREQUAL "Cthugha")
#  message(SEND_ERROR "You need Ogre 1.7 Cthugha to build this.")
#endif()
 
find_package(OIS REQUIRED)
 
if(NOT OIS_FOUND)
	message(SEND_ERROR "Failed to find OIS.")
endif()
 
# Find Boost
if (NOT OGRE_BUILD_PLATFORM_IPHONE)
	if (WIN32 OR APPLE)
		set(Boost_USE_STATIC_LIBS TRUE PARENT_SCOPE)
	else ()
		# Statically linking boost to a dynamic Ogre build doesn't work on Linux 64bit
		set(Boost_USE_STATIC_LIBS ${OGRE_STATIC} PARENT_SCOPE)
	endif ()
	if (MINGW)
		# this is probably a bug in CMake: the boost find module tries to look for
		# boost libraries with name libboost_*, but CMake already prefixes library
		# search names with "lib". This is the workaround.
		set(CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "" PARENT_SCOPE)
	endif ()
	set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37"  PARENT_SCOPE)
	# Components that need linking (NB does not include header-only components like bind)
	set(OGRE_BOOST_COMPONENTS thread date_time PARENT_SCOPE)
	find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	FIND_PACKAGE(Boost)
	
	if (NOT Boost_FOUND)
		# Try again with the other type of libs
		set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS} PARENT_SCOPE)
		find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	endif()
	find_package(Boost QUIET)
 
	# Set up referencing of Boost
	add_definitions(-DBOOST_ALL_NO_LIB)
	set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES} PARENT_SCOPE)
endif()






set(HDRS
	${HDRS}
	${CMAKE_CURRENT_SOURCE_DIR}/include/Whitedrop.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/base.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/Entity.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/World.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/Vector3.h
	PARENT_SCOPE
)
 
set(SRCS
	${SRCS}
	${CMAKE_CURRENT_SOURCE_DIR}/lib/Whitedrop.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/lib/Entity.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/lib/World.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/lib/Vector3.cpp
	PARENT_SCOPE
)

set(DIR_TO_INCLUDE
	${DIR_TO_INCLUDE}
	${Boost_INCLUDE_DIR}
	# ./engine/include/
	${OIS_INCLUDE_DIRS}
	${OGRE_INCLUDE_DIRS}
	${OGRE_SAMPLES_INCLUDEPATH}
	${OGRE_Overlay_INCLUDE_DIRS}
	PARENT_SCOPE
)

set(TARGET_LIBRARIES
	${TARGET_LIBRARIES}
	${OGRE_LIBRARIES}
	${OIS_LIBRARIES}
	${OGRE_Overlay_LIBRARIES}
	${Boost_LIBRARIES}
	PARENT_SCOPE
)
# file(GLOB_RECURSE MEDIA_FILES ${CMAKE_SOURCE_DIR}/dist/media/*)
# foreach(FILE_TO_COPY ${MEDIA_FILES})
# 	get_filename_component(FILE_DIR ${FILE_TO_COPY} DIRECTORY)
# 	string(LENGTH ${CMAKE_SOURCE_DIR}/dist/media/ STRING_LENGTH)
# 	string(SUBSTRING ${FILE_DIR} ${STRING_LENGTH} -1 RELATIVE_FILE)
# 	file(INSTALL ${FILE_TO_COPY} DESTINATION ${CMAKE_BINARY_DIR}/dist/media/${RELATIVE_FILE})
# endforeach(FILE_TO_COPY)
# install(DIRECTORY ${CMAKE_SOURCE_DIR}/dist/media/ DESTINATION ${CMAKE_BINARY_DIR}/dist/ FILES_MATCHING PATTERN "*")
# IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
file(INSTALL
	${OGRE_BINARY_DBG}
	${OGRE_Overlay_BINARY_DBG} 
	${OGRE_BINARY_REL} 
	${OGRE_Overlay_BINARY_REL} 
	${OIS_BINARY_DBG}
	${OIS_BINARY_REL}
	${OGRE_RenderSystem_Direct3D11_REL}
	${OGRE_RenderSystem_Direct3D11_DBG}
	${OGRE_RenderSystem_GL_DBG}
	${OGRE_RenderSystem_GL_REL}
	${OGRE_Terrain_BINARY_DBG}
	${OGRE_Terrain_BINARY_REL}
	${OGRE_Volume_BINARY_DBG}
	${OGRE_Volume_BINARY_REL}
	DESTINATION ${CMAKE_BINARY_DIR}/dist/bin)
# ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)
