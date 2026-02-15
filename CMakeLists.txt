cmake_minimum_required(VERSION 4.1)
project(c_data_structures C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(test_vector tests/test_vector.c src/vector.c)