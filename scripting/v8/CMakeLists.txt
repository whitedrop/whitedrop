 if(WIN32)
 	set(V8_PREFIX_GUESS "C:/ChromeV8/v8/")
 endif()
 find_path(V8_INCLUDE_DIR NAMES v8.h HINTS ${V8_PREFIX_GUESS} PATH_SUFFIXES include )
 find_path(V8_LIBRARY_DIR_REL NAMES v8_base.lib PATHS ${V8_PREFIX_GUESS} PATH_SUFFIXES build/Release/lib)
 find_path(V8_LIBRARY_DIR_DBG NAMES v8_base.lib PATHS ${V8_PREFIX_GUESS} PATH_SUFFIXES build/Debug/lib)
 IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
     message("debug mode")
 	set(TARGET_LIBRARIES
 		${TARGET_LIBRARIES}
 		${V8_LIBRARY_DIR_DBG}/icui18n.lib
 		${V8_LIBRARY_DIR_DBG}/icuuc.lib
 		${V8_LIBRARY_DIR_DBG}/v8_base.lib
 		${V8_LIBRARY_DIR_DBG}/v8_libbase.lib
 		${V8_LIBRARY_DIR_DBG}/v8_libplatform.lib
 		${V8_LIBRARY_DIR_DBG}/v8_snapshot.lib
 		PARENT_SCOPE
 	)
 elseif(CMAKE_BUILD_TYPE MATCHES RELEASE)
     message("rel mode")
 	set(TARGET_LIBRARIES
 		${TARGET_LIBRARIES}
 		${V8_LIBRARY_DIR_REL}/icui18n.lib
 		${V8_LIBRARY_DIR_REL}/icuuc.lib
 		${V8_LIBRARY_DIR_REL}/v8_base.lib
 		${V8_LIBRARY_DIR_REL}/v8_libbase.lib
 		${V8_LIBRARY_DIR_REL}/v8_libplatform.lib
 		${V8_LIBRARY_DIR_REL}/v8_snapshot.lib
 		PARENT_SCOPE
 	)
 else()
 	message("def")
 	set(TARGET_LIBRARIES
 		${TARGET_LIBRARIES}
 		${V8_LIBRARY_DIR_DBG}/icui18n.lib
 		${V8_LIBRARY_DIR_DBG}/icuuc.lib
 		${V8_LIBRARY_DIR_DBG}/v8_base.lib
 		${V8_LIBRARY_DIR_DBG}/v8_libbase.lib
 		${V8_LIBRARY_DIR_DBG}/v8_libplatform.lib
 		${V8_LIBRARY_DIR_DBG}/v8_snapshot.lib
 		PARENT_SCOPE
 	)
 endif()
 set(DIR_TO_INCLUDE
 	${DIR_TO_INCLUDE}
 	# ${V8_INCLUDE_DIR}
 	${V8_PREFIX_GUESS}
 	PARENT_SCOPE
 )


set(HDRS
	${HDRS}
	${CMAKE_CURRENT_SOURCE_DIR}/include/Interface.h
	PARENT_SCOPE
)
 
set(SRCS
	${SRCS}
	${CMAKE_CURRENT_SOURCE_DIR}/lib/Interface.cpp
	PARENT_SCOPE
)
