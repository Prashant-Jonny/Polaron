cmake_minimum_required (VERSION 2.8)

If(NOT SRC_DIR)
  SET(SRC_DIR ${CMAKE_CURRENT_LIST_DIR})
EndIf()

include_directories("${SRC_DIR}")

file(SRC "${SRC_DIR}/Polaron/")

add_executable(Polaron ${SRC})

cotire(Polaron)