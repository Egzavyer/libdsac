project(gtest CXX)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(gtestlib)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run DArrayTest.cpp)

target_link_libraries(Google_Tests_run dsa)

target_link_libraries(Google_Tests_run gtest gtest_main)