cmake_minimum_required(VERSION 2.8.7)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#include(cotire)

project(Polaron)

If(NOT POLARON_SRC_DIR)
  SET(POLARON_SRC_DIR ${CMAKE_CURRENT_LIST_DIR})
  Message("-- Initializing POLARON_SRC_DIR=${POLARON_SRC_DIR}")
EndIf()

include_directories("${POLARON_SRC_DIR}")

add_executable(
Polaron
"${POLARON_SRC_DIR}/Polaron/Polaron.cpp"
"${POLARON_SRC_DIR}/Polaron/*")

target_link_libraries(Polaron)

#set_target_properties(Polaron PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${POLARON_SRC_DIR}/stdafx.h")
#cotire(Polaron)