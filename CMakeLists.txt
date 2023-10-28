cmake_minimum_required(VERSION 3.24)

project(DIJKSTRA_D_HEAP)

include(function.cmake)

add_subdirectory(mylibrary)

add_subdirectory(Dijkstra)

option(BTEST "build test?" OFF)

if(BTEST)
    add_subdirectory(test)
endif()

