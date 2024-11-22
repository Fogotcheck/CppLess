cmake_minimum_required(VERSION 3.22)

add_library(${TaskName}Lib INTERFACE)

add_subdirectory(MyQueue)
add_subdirectory(MyList)
add_subdirectory(MyStruct)
