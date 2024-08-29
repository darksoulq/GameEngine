cmake_minimum_required(VERSION 3.10)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(headers)

# Source files
file(GLOB SOURCES src/*.cpp)

# Executable
add_executable(GameEngine 
${SOURCES} 
main.cpp
MenuScene.cpp
GameScene.cpp)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(GameEngine ${SDL2_LIBRARIES})

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(GameEngine ${OPENGL_LIBRARIES})

# GLEW
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLEW REQUIRED glew)
include_directories(${GLEW_INCLUDE_DIRS})
target_link_libraries(GameEngine ${GLEW_LIBRARIES})

# stb_image
find_package(PkgConfig REQUIRED)
pkg_check_modules(STB REQUIRED stb)
include_directories(${STB_INCLUDE_DIRS})
target_link_libraries(GameEngine ${STB_LIBRARIES})
