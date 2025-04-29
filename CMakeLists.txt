cmake_minimum_required(VERSION 3.10)
project(OcclusionCulling CXX)

find_package(Catch2 3 REQUIRED)

add_subdirectory(utils)
add_subdirectory(tests)

add_executable(main main.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(main PUBLIC utils)