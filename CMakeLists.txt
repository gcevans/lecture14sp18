cmake_minimum_required(VERSION 3.9)
project(lecture14)

set(CMAKE_CXX_STANDARD 14)

add_executable(lecture14 main.cpp studentinfo.cpp studentinfo.h gradebook.h gradebook.cpp)