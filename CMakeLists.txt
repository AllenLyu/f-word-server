cmake_minimum_required(VERSION 3.5)
project(f_word_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    socket/server.c
    socket/http_example
        )

add_executable(f_word_server ${SOURCE_FILES})