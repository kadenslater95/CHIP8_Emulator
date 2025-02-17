cmake_minimum_required(VERSION 3.14)
project(implementations)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -Wall -g ${GTK4_CFLAGS}")


include_directories(include)
include_directories(${GTK4_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})
#include_directories(${OPENGL_INCLUDE_DIRS})


add_library(file_utils STATIC src/file_utils.c)
add_library(display_utils STATIC src/display_utils.c)

add_executable(main src/main.c)


target_link_libraries(display_utils PRIVATE PkgConfig::GTK4 file_utils OpenGL::GL OpenGL::GLU GLEW::glew)

target_link_libraries(main display_utils)
