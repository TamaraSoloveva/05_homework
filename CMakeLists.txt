cmake_minimum_required(VERSION 3.5)

project(05_homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(05_homework main.cpp statistics_min.cpp statistics.h statistics_max.cpp
               statistics_mean.cpp  statistics_std.cpp  statistics_pct.cpp )
