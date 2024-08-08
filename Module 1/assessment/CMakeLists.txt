cmake_minimum_required(VERSION 3.28)
project(assessment C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(assessment
        stats.c
        stats.h)
