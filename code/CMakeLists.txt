cmake_minimum_required(VERSION 3.10)
project(CGProject)

find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include ./include)

add_executable(CGProject main.cpp rasterizer.hpp rasterizer.cpp Triangle.hpp Triangle.cpp Texture.hpp Texture.cpp Shader.hpp OBJ_Loader.h Pixel.hpp)