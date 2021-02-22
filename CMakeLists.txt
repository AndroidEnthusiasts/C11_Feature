cmake_minimum_required(VERSION 3.10)
project(C__11_feature)
set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package (Threads)
add_executable (C__11_feature main.cpp)
add_executable (function function.cpp)
target_link_libraries (C__11_feature ${CMAKE_THREAD_LIBS_INIT})





