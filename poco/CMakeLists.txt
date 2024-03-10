cmake_minimum_required(VERSION 3.20)
project(Poco)

find_package(Poco REQUIRED Net Util JSON Foundation)

# web server
add_executable(${CMAKE_PROJECT_NAME}_web_server web_server.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_web_server PRIVATE Poco::Net Poco::Util)

# json
add_executable(${CMAKE_PROJECT_NAME}_json_string json_string.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_json_string PRIVATE Poco::JSON)

add_executable(${CMAKE_PROJECT_NAME}_json_file json_file.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_json_file PRIVATE Poco::JSON)

# thread
add_executable(${CMAKE_PROJECT_NAME}_thread multi_thread.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_thread PRIVATE Poco::Foundation)

# date time
add_executable(${CMAKE_PROJECT_NAME}_date_time date_time.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_date_time PRIVATE Poco::Foundation)
