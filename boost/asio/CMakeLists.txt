cmake_minimum_required(VERSION 3.20)
project(CppAsio)

find_package(Boost REQUIRED)

# http
add_executable(${CMAKE_PROJECT_NAME}_http_server http_server.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_http_server PRIVATE Boost::boost)

add_executable(${CMAKE_PROJECT_NAME}_http_client http_client.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_http_client PRIVATE Boost::boost)

# tcp
add_executable(${CMAKE_PROJECT_NAME}_tcp_server tcp_server.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_tcp_server PRIVATE Boost::boost)

add_executable(${CMAKE_PROJECT_NAME}_tcp_client tcp_client.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_tcp_client PRIVATE Boost::boost)

# udp
add_executable(${CMAKE_PROJECT_NAME}_udp_server udp_server.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_udp_server PRIVATE Boost::boost)

add_executable(${CMAKE_PROJECT_NAME}_udp_client udp_client.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_udp_client PRIVATE Boost::boost)

# websocket
add_executable(${CMAKE_PROJECT_NAME}_websocket_server websocket_server.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_websocket_server PRIVATE Boost::boost)

add_executable(${CMAKE_PROJECT_NAME}_websocket_client websocket_client.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_websocket_client PRIVATE Boost::boost)

# websocket2
add_executable(${CMAKE_PROJECT_NAME}_ws_server ws_server.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_ws_server PRIVATE Boost::boost)

add_executable(${CMAKE_PROJECT_NAME}_ws_client ws_client.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_ws_client PRIVATE Boost::boost)
