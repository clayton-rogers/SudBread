cmake_minimum_required(VERSION 3.1)
project(SudBread_clion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/fileop.cpp
    src/gridop.cpp
    src/main.cpp
    src/solver.cpp
    src/timetrial.cpp
    src/timer.cpp
    src/stringop.cpp
)

add_executable(SudBread_clion ${SOURCE_FILES})