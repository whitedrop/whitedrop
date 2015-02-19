
set(HDRS
	${HDRS}
	${CMAKE_CURRENT_SOURCE_DIR}/include/QuantumEngine.h
	PARENT_SCOPE
)
set(HDRS
	${HDRS}
	${CMAKE_CURRENT_SOURCE_DIR}/default/include/DefaultQEngine.h
	PARENT_SCOPE
)
 
set(SRCS
	${SRCS}
	${CMAKE_CURRENT_SOURCE_DIR}/default/src/DefaultQEngine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/default/src/DefaultQEntity.cpp
	PARENT_SCOPE
)
set(DIR_TO_INCLUDE
	${DIR_TO_INCLUDE}
	${CMAKE_CURRENT_SOURCE_DIR}/include/
	PARENT_SCOPE)
