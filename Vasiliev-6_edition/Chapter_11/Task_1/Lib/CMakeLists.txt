cmake_minimum_required(VERSION 3.22)

add_library(${TaskName}Lib INTERFACE)

add_subdirectory(ComplexBase)
add_subdirectory(ComplexDervid)
