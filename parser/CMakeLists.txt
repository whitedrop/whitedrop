

set(HDRS
	${HDRS}
	${CMAKE_CURRENT_SOURCE_DIR}/include/parser.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/picojson.h
	PARENT_SCOPE
)
 
set(SRCS
	${SRCS}
	${CMAKE_CURRENT_SOURCE_DIR}/lib/parser.cpp
	PARENT_SCOPE
)