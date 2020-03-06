cmake_minimum_required(VERSION 3.15)
project(JNI)

set(CMAKE_CXX_STANDARD 14)

#add_library(JNI SHARED library.cpp library.h)
add_library(firstdylib SHARED DynamicRegister.c)