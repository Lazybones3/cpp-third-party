cmake_minimum_required(VERSION 3.20)
project(CppThread)

find_package(Boost REQUIRED thread)

add_executable(${CMAKE_PROJECT_NAME}_thread thread.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_thread PRIVATE Boost::thread)
