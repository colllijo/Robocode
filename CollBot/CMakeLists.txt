cmake_minimum_required(VERSION 3.22)

project(CollBot)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} CollBot.cpp CollBot.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE coll-tankroyal-botapi fmt::fmt ixwebsocket::ixwebsocket nlohmann_json::nlohmann_json)
