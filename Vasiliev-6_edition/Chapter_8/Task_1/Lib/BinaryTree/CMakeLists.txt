cmake_minimum_required(VERSION 3.22)

add_library(
    MyTree
    Src/MyTree.cpp
)

target_include_directories(
    ${TaskName}Lib
    INTERFACE
    Inc
)
target_link_libraries(
    MyTree
    ${TaskName}Lib
)
target_link_libraries(
    ${TaskName}Lib
    INTERFACE
    MyTree
)
