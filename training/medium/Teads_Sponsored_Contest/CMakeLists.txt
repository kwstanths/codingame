cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11)

set(NAME "Teads_Sponsored_Contest")
project(${NAME})

file(GLOB ${NAME}_HEADERS *.hpp)
file(GLOB ${NAME}_SOURCES *.cpp)

add_executable(${NAME} ${${NAME}_HEADERS} ${${NAME}_SOURCES})
