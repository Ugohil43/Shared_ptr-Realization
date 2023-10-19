cmake_minimum_required(VERSION 3.5.0)

set(SOURCES
    ./src/My_shared_ptr.hpp
    )

include_directories(
    ./src/
    )
add_executable(application ./src/main.cpp ${SOURCES})