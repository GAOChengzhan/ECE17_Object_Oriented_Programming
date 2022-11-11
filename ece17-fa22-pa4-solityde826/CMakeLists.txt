cmake_minimum_required(VERSION 3.10)
project(Assignment4)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
if (DEFINED ENV{CLION_IDE})
    add_compile_options(-isysroot ${CMAKE_OSX_SYSROOT})
endif()