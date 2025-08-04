cmake_minimum_required(VERSION 3.22.1)
project(examples-needle-increment VERSION 1.0)

add_executable(examples-increment examples/needle/increment.c)

target_include_directories(examples-increment PUBLIC .)