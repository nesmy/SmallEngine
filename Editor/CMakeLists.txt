cmake_minimum_required(VERSION 3.2)

project(Editor)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(C:/Users/pnesm/OneDrive/Bureau/Playground/SmallEngine/Library ../lib)

target_include_directories(${PROJECT_NAME}
    PUBLIC C:/Users/pnesm/OneDrive/Bureau/Playground/SmallEngine/Library/include
    )

target_link_directories(${PROJECT_NAME}
    PUBLIC C:/Users/pnesm/OneDrive/Bureau/Playground/SmallEngine/Library/src
    )

target_link_libraries(${PROJECT_NAME}
    small
    )