add_executable(${PROJECT_NAME}_node
    main.cpp
)
target_link_libraries( ${PROJECT_NAME}_node
    plugin_1
)