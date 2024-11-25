cmake_minimum_required(VERSION 3.22)

add_library(
    MyNewList
    Src/MyNewList.cpp
)

target_include_directories(
    ${TaskName}Lib
    INTERFACE
    Inc
)
target_link_libraries(
    MyNewList
    ${TaskName}Lib
)
target_link_libraries(
    ${TaskName}Lib
    INTERFACE
    MyNewList
)
