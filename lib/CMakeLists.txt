cmake_minimum_required(VERSION 3.22)

project(CollTankRoyalLibrary VERSION 1.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(coll-botapi)
add_subdirectory(IXWebSocket)
add_subdirectory(fmt)
add_subdirectory(json)
