cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 14)

project(SmallLaucher)

set (HEADER_FILES
    include/pch.h)
file(GLOB SOURCES src/*.cpp ../Library/vendor/imgui/backends/imgui_impl_opengl3.cpp ../Library/vendor/imgui/backends/imgui_impl_glfw.cpp ${HEADER_FILES} )

add_executable(${PROJECT_NAME} ${SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE ${HEADER_FILES})

add_compile_definitions(UNICODE)

#add_subdirectory(vendor/glad)
#add_subdirectory(vendor/glfw)
#add_subdirectory(vendor/spdlog)
#add_subdirectory(vendor/imgui)
#add_subdirectory(vendor/glm)
#add_subdirectory(vendor/assimp)

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
#  COMMAND "${CMAKE_COMMAND}" -E copy 
#     "$<TARGET_FILE:SmallLauncher>"
#     "../$<TARGET_FILE_NAME:SmallLauncher>" 
#  COMMENT "Copying to output directory")


target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PUBLIC ../Library/vendor/glad/include
    PUBLIC ../Library/vendor/glad/src
    PUBLIC ../Library/vendor/glfw/include
    PUBLIC ../Library/vendor/spdlog/include
    PUBLIC ../Library/vendor/imgui
    PUBLIC ../Library/vendor/glm/glm
    PUBLIC ../Library/vendor/assimp/include)

target_link_directories(${PROJECT_NAME}
    PUBLIC ../Library/vendor/glad/src
    PUBLIC ../Library/vendor/glfw/src
    PUBLIC ../Library/vendor/imgui)

target_link_libraries(${PROJECT_NAME}
    glad
    ${OPENGL_LIBRARIES}
    glfw
    imgui
    glm
    #assimp
    )
