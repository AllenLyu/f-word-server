cmake_minimum_required(VERSION 3.5)
project(f_word_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    socket/server.c
    socket/http_example
        http/f_word_request.h http/f_word_request.c http/f_word_reqponse.c http/f_word_reqponse.h)

add_executable(f_word_server ${SOURCE_FILES})