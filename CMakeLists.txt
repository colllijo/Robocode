cmake_minimum_required(VERSION 3.22)

project(CollTankRoyal VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

add_subdirectory(CollBot)
add_subdirectory(lib)
