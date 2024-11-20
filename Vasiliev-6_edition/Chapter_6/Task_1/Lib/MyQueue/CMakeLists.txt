cmake_minimum_required(VERSION 3.22)

add_library(
    MyQueue
    Src/MyQueue.cpp
)

target_include_directories(
    ${TaskName}Lib
    INTERFACE
    Inc
)
target_link_libraries(
    MyQueue
    ${TaskName}Lib
)
target_link_libraries(
    ${TaskName}Lib
    INTERFACE
    MyQueue
)
