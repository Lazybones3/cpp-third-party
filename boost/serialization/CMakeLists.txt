cmake_minimum_required(VERSION 3.20)
project(CppThread)

find_package(Boost REQUIRED serialization)

add_executable(${CMAKE_PROJECT_NAME}_serialization serialization.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_serialization PRIVATE Boost::serialization)
