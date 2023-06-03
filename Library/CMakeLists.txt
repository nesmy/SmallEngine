cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 14)

project(small)

set (HEADER_FILES
    include/pch.h)
file(GLOB SOURCES src/*.cpp src/Small/*.cpp src/Small/ImGui/*.cpp src/Platform/*.cpp src/Platform/OpenGl/*.cpp ${HEADER_FILES} )

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE ${HEADER_FILES})

add_compile_definitions(UNICODE)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/imgui)
add_subdirectory(vendor/glm)
#add_subdirectory(vendor/assimp)


target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PUBLIC vendor/glad/include
    PUBLIC vendor/glad/src
    PUBLIC vendor/glfw/include
    PUBLIC vendor/spdlog/include
    PUBLIC vendor/imgui
    PUBLIC vendor/glm/glm
    PUBLIC vendor/assimp/include)

target_link_directories(${PROJECT_NAME}
    PUBLIC vendor/glad/src
    PUBLIC vendor/glfw/src
    PUBLIC vendor/imgui)

target_link_libraries(${PROJECT_NAME}
    glad
    ${OPENGL_LIBRARIES}
    glfw
    imgui
    glm
    #assimp
    )
