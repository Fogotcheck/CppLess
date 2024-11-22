cmake_minimum_required(VERSION 3.22)

add_library(
    MyComplAlg
    Src/ComplexAlg.cpp
)

target_include_directories(
    ${TaskName}Lib
    INTERFACE
    Inc
)
target_link_libraries(
    MyComplAlg
    ${TaskName}Lib
)
target_link_libraries(
    ${TaskName}Lib
    INTERFACE
    MyComplAlg
)
