cmake_minimum_required(VERSION 3.15)
project(dsa_book C)

set(CMAKE_C_STANDARD 99)

add_executable(dsa_book main.c cda.c cda.h cdap.h linked_list/linked_list.c linked_list/linked_list.h)