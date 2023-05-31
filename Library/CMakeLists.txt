cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 14)

project(small)

file(GLOB SOURCES src/*.cpp vendor/imgui/backends/imgui_impl_glfw.cpp vendor/imgui/backends/imgui_impl_opengl3.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

add_compile_definitions(UNICODE)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/imgui)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/assimp)


target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PUBLIC vendor/glad/include
    PUBLIC vendor/glad/src
    PUBLIC vendor/glfw/include
    PUBLIC vendor/spdlog/include
    PUBLIC vendor/spdlog/src
    PUBLIC vendor/imgui
    PUBLIC vendor/imgui/backends
    PUBLIC vendor/glm/glm
    PUBLIC vendor/assimp/include)

target_link_directories(${PROJECT_NAME}
    PUBLIC vendor/glad/src
    PUBLIC vendor/glfw/src
    PUBLIC vendor/spdlog/src
    PUBLIC vendor/imgui
    PUBLIC vendor/imgui/backends)

target_link_libraries(${PROJECT_NAME}
    glad
    ${OPENGL_LIBRARIES}
    opengl32
    glfw
    spdlog
    imgui-stdlib
    imgui
    glm
    assimp)