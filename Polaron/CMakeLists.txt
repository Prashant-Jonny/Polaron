cmake_minimum_required(VERSION 2.8.7)

#include(cotire)

project(Polaron)

if(NOT MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

If(NOT POLARON_SRC_DIR)
  SET(POLARON_SRC_DIR ${CMAKE_CURRENT_LIST_DIR})
  Message("-- Initializing POLARON_SRC_DIR=${POLARON_SRC_DIR}")
EndIf()

include_directories("${POLARON_SRC_DIR}")

file(GLOB POLARON_SRC "${POLARON_SRC_DIR}/Polaron/*")
add_executable(Polaron ${POLARON_SRC})

target_link_libraries(Polaron)

#set_target_properties(Polaron PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${POLARON_SRC_DIR}/stdafx.h")
#cotire(Polaron)