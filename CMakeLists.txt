cmake_minimum_required(VERSION 3.19)
project(ziya_linux_teach)

set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread")

set(CMAKE_CXX_STANDARD 14)

add_executable(ziya_linux_teach main.cpp include/common.h thread/test-thread-return.cpp)