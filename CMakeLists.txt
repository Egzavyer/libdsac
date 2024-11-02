cmake_minimum_required(VERSION 3.20)
project(DArray)

set(SOURCES main.c src/ds/DArray.c)

add_executable(DArray ${SOURCES})

target_include_directories(DArray PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)