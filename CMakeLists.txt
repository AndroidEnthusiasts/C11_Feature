cmake_minimum_required(VERSION 3.10)
project(C__11_feature)
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
#find_package (Threads)
add_executable (C__11_feature main.cpp)
add_executable (function function.cpp)
add_executable (bind bind.cpp)
add_executable(vt variadictemplate.cpp)
add_executable(nullptr nullptr.cpp)
add_executable(auto auto.cpp)

add_executable(explicit explicit.cpp)
add_executable(decltype decltype.cpp)
add_executable(lambda lambda.cpp)


add_executable(Thread thread/Thread.cpp)
add_executable(unique_lock thread/unique_lock.cpp)
add_executable(condition thread/condition.cpp)
add_executable(testdectype Testdecltype.cpp)


add_executable(un UniformInitialization.cpp)
add_executable (threadpool threadpool/threadpool.h threadpool/TestThreadPool.cpp)


# ${CMAKE_THREAD_LIBS_INIT}
target_link_libraries (threadpool pthread)





