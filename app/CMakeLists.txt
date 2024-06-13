add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE tesselation_lib glfw glad imgui ecs algebra stb_image)
