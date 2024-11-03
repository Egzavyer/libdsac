cmake_minimum_required(VERSION 3.20)
project(dsa)

set(SOURCES main.c 
    src/ds/darray.c 
    src/ds/llist.c
    src/ds/stack.c
    src/algos/insertionSort.c
    src/algos/selectionSort.c 
    src/algos/bubbleSort.c)

add_executable(dsa ${SOURCES})

target_include_directories(dsa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)