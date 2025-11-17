cmake_minimum_required(VERSION 3.10)
project(sorting_benchmark)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(sorting_benchmark
    src/main.cpp
    src/utils.cpp
    src/bubble.cpp
    src/selection.cpp
    src/insertion.cpp
    src/merge.cpp
    src/quick.cpp
)
