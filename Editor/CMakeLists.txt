cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 14)

project(Editor)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(../Library ../lib)

target_include_directories(${PROJECT_NAME}
    PUBLIC ../Library/include
    )

target_link_directories(${PROJECT_NAME}
    PUBLIC ../Library/src
    )

target_link_libraries(${PROJECT_NAME}
    small
    )
