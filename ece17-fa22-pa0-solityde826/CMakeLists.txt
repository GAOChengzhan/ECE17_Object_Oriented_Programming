cmake_minimum_required(VERSION 3.17)
project(pa0)

set(CMAKE_CXX_STANDARD 17)

add_executable(pa0 main.cpp AboutMe.cpp)
add_executable(test main.cpp AboutMe.cpp)