cmake_minimum_required(VERSION 3.14)
project(CHIP8_Emulator)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)


add_subdirectory(src)
add_subdirectory(test)
