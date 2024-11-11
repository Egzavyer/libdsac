cmake_minimum_required(VERSION 3.20)
project(dsa)

set(SOURCES main.c 
    src/common.c
    src/ds/darray.c 
    src/ds/llist.c
    src/ds/stack.c
    src/ds/queue.c
    src/algos/mergeSort.c
    src/algos/insertionSort.c
    src/algos/selectionSort.c 
    src/algos/bubbleSort.c)

add_executable(dsa ${SOURCES})
target_include_directories(dsa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#[[add_library(dsa STATIC ${SOURCES})

target_include_directories(dsa
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(TARGETS dsa
    EXPORT dsa-config
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ds DESTINATION include)
install(DIRECTORY include/ds DESTINATION include)

install(EXPORT dsa-config NAMESPACE dsa:: DESTINATION lib/cmake/dsa)]]

