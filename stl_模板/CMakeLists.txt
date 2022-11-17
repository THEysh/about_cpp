cmake_minimum_required(VERSION 3.22)
project(stl_)

set(CMAKE_CXX_STANDARD 20)

add_executable(stl_ main.cpp template.cpp template.h person.cpp person.hpp)
