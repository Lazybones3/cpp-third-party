cmake_minimum_required(VERSION 3.20)
project(CppThread)

find_package(Boost REQUIRED date_time)

add_executable(${CMAKE_PROJECT_NAME}_date_time date_time.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_date_time PRIVATE Boost::date_time)
