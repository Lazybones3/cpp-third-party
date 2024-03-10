cmake_minimum_required(VERSION 3.20)
project(Poco)

find_package(Poco REQUIRED Net Util JSON)

# web server
add_executable(${CMAKE_PROJECT_NAME}_web_server web_server.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_web_server PRIVATE Poco::Net Poco::Util)

# json
add_executable(${CMAKE_PROJECT_NAME}_json_string json_string.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_json_string PRIVATE Poco::JSON)

add_executable(${CMAKE_PROJECT_NAME}_json_file json_file.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_json_file PRIVATE Poco::JSON)