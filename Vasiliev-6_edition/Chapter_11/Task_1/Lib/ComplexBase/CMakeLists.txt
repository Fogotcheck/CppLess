cmake_minimum_required(VERSION 3.22)

add_library(
    ComplexBase
    Src/ComplexBase.cpp
)

target_include_directories(
    ${TaskName}Lib
    INTERFACE
    Inc
)
target_link_libraries(
    ComplexBase
    ${TaskName}Lib
)
target_link_libraries(
    ${TaskName}Lib
    INTERFACE
    ComplexBase
)
