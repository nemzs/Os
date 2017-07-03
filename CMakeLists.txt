cmake_minimum_required(VERSION 3.7)
project(test_epoll)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(test_epoll ${SOURCE_FILES})