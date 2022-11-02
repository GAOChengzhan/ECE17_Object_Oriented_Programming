cmake_minimum_required(VERSION 3.10)
project(assignment2)

set(CMAKE_CXX_STANDARD 11)

include_directories(./)

add_executable(main main.cpp MadLibsController.cpp MadlibUserWordProvider.cpp MadlibAutoWordProvider.cpp)
