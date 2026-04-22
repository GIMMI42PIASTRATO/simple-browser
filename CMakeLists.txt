cmake_minimum_required(VERSION 4.1.0)
project(simplebrowser)
add_executable(${PROJECT_NAME} src/main.c
    src/lexer.c
    include/lexer.h)

target_include_directories(${PROJECT_NAME} PRIVATE include)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
