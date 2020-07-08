cmake_minimum_required(VERSION 3.16)
project(test C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(test
        checker.h
        checker1.c
        checker2.c
        checker3.c
        checker4.c
        checker5.c
        print_action.c
        push_swap.c
        sort.c
        sort1.c
        sort2.c
        sort3.c)
