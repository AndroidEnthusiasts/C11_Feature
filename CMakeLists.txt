cmake_minimum_required(VERSION 3.10)
project(C__11_feature)
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
#find_package (Threads)
add_executable (C__11_feature main.cpp)
add_executable (function function.cpp)
add_executable (bind bind.cpp)

add_executable (threadpool threadpool/threadpool.h threadpool/TestThreadPool.cpp)

# ${CMAKE_THREAD_LIBS_INIT}
target_link_libraries (threadpool pthread)





