cmake_minimum_required(VERSION 3.7)
project(C__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)

file(GLOB SOURCES
        "src/**/*.cpp"
        "src/**/*.hpp"
        "src/**/*.h"
        "src/*.h"
        "src/*.cpp"
        "src/*.c"
        )

add_executable(C__ ${SOURCE_FILES} ${SOURCES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")
