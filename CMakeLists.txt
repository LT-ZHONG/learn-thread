cmake_minimum_required(VERSION 3.16)
project(learn_thread)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(learn_thread main.cpp A.cpp)

target_link_libraries(learn_thread PRIVATE Threads::Threads)
