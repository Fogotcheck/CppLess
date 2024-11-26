cmake_minimum_required(VERSION 3.22)

add_library(
    ComplexDervid
    Src/ComplexDervid.cpp
)

target_include_directories(
    ${TaskName}Lib
    INTERFACE
    Inc
)
target_link_libraries(
    ComplexDervid
    ${TaskName}Lib
)
target_link_libraries(
    ${TaskName}Lib
    INTERFACE
    ComplexDervid
)
