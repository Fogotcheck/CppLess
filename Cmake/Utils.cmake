cmake_minimum_required(VERSION 3.22)

add_custom_target(
    Install_${PROJECT_NAME}
    COMMAND CPack -G ZIP
    COMMENT "Installing ${PROJECT_NAME}"
)

function(add_task_solution TargetName)
    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        target_link_options(
            ${TargetName}
            PRIVATE
            /MAP:${TargetName}.map)
    else()
        target_link_options(
            ${TargetName}
            PRIVATE
            -Wl,-Map,${TargetName}.map)
    endif()

    add_dependencies(
        Install_${PROJECT_NAME}
        ${TargetName}
    )

    install(TARGETS ${TargetName} DESTINATION bin/${TargetName})
    install(FILES ${CMAKE_BINARY_DIR}/${TargetName}.map DESTINATION bin/${TargetName})
endfunction(add_task_solution TargetName)
