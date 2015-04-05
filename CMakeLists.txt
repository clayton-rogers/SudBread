cmake_minimum_required(VERSION 3.1)
project(SudBread_clion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 \
    -pedantic -Wall -Wextra -Wcast-align \
    -Wcast-qual -Wctor-dtor-privacy \
    -Wdisabled-optimization -Wformat=2 \
    -Winit-self -Wlogical-op -Wmissing-declarations \
    -Wmissing-include-dirs -Wnoexcept -Wold-style-cast \
    -Woverloaded-virtual -Wredundant-decls -Wshadow \
    -Wsign-conversion -Wsign-promo \
    -Wstrict-null-sentinel -Wstrict-overflow=5 \
    -Wswitch-default -Wundef -Wno-unused")

set(SOURCE_FILES
    src/fileop.cpp
    src/gridop.cpp
    src/main.cpp
    src/solver.cpp
    src/timetrial.cpp
    src/timer.cpp
    src/stringop.cpp
    src/CSquare.h
)

add_executable(SudBread_clion ${SOURCE_FILES})