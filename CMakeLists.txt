cmake_minimum_required(VERSION 3.5)

project(05_homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(05_homework main.cpp statistics_min.cpp statistics.h statistics_max.cpp
               statistics_mean.cpp  statistics_std.cpp  statistics_pct.cpp )

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(05_homework PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(04_homework PRIVATE /EHsc /W4 /WX)

 endif()
