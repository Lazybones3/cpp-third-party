cmake_minimum_required(VERSION 3.20)
project(Poco)

find_package(Poco REQUIRED Net Util)

add_executable(${CMAKE_PROJECT_NAME}_web_server web_server.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_web_server PRIVATE Poco::Net Poco::Util)