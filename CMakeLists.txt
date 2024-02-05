cmake_minimum_required(VERSION 3.27)
project(dsa)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(dsa main.cpp
        src/Deque.h)
