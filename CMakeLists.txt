cmake_minimum_required(VERSION 3.10)
project(stack C)

set(CMAKE_C_STANDARD 11)

add_executable(stack main.c stack.h stack.c)