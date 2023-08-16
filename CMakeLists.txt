cmake_minimum_required(VERSION 3.16)

project(learn_thread)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(learn_thread main.cpp)
add_executable(rvalue_reference A.cpp)
add_executable(move_semantics B.cpp)
add_executable(thread_with_move_semantics tms.cpp)
add_executable(thread_with_shared_memory tsm.cpp)
add_executable(race_condition race_condition.cpp)

target_link_libraries(learn_thread PRIVATE Threads::Threads)
target_link_libraries(thread_with_move_semantics PRIVATE Threads::Threads)
target_link_libraries(thread_with_shared_memory PRIVATE Threads::Threads)
target_link_libraries(race_condition PRIVATE Threads::Threads)
