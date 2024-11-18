cmake_minimum_required(VERSION 3.22)

set(TaskName "${PROJECT_NAME}-${Chapter}-Task_3")

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
add_task_solution(${TaskName})
