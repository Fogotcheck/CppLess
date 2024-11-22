cmake_minimum_required(VERSION 3.22)

add_library(
    MyStruct
    Src/MyStruct.cpp
)

target_include_directories(
    ${TaskName}Lib
    INTERFACE
    Inc
)
target_link_libraries(
    MyStruct
    ${TaskName}Lib
)
target_link_libraries(
    ${TaskName}Lib
    INTERFACE
    MyStruct
)
