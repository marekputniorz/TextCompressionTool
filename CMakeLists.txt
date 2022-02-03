cmake_minimum_required(VERSION 3.4)

project(zipper)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

add_executable(zipper projekt.c)