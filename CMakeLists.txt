cmake_minimum_required(VERSION 3.22.1)
project(examples-needle-increment VERSION 1.0)
project(examples-smpld-repeat VERSION 1.0)

add_executable(examples-needle-increment examples/needle/increment.c)
add_executable(examples-smpld-repeat examples/smpld/repeat.c)

target_include_directories(examples-needle-increment PUBLIC .)
target_include_directories(examples-smpld-repeat PUBLIC .)