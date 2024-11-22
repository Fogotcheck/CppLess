cmake_minimum_required(VERSION 3.22)

set(TaskName "${PROJECT_NAME}-${Chapter}-Task_13")

add_subdirectory(Lib)
add_executable(${TaskName})

target_sources(
    ${TaskName}
    PRIVATE
    AppMain/Main.cpp
)
target_include_directories(
    ${TaskName}
    PRIVATE
    AppMain
)

target_link_libraries(
    ${TaskName}
    ${TaskName}Lib
)
add_task_solution(${TaskName})
