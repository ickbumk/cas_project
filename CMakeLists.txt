cmake_minimum_required(VERSION 3.10)
project(OcclusionCulling CXX)

find_package(Catch2 CONFIG REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(utils)
add_subdirectory(culling)
add_subdirectory(tests)

add_executable(main main.cpp)

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(main PUBLIC utils culling ${OpenCV_LIBS})

message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include directories: ${OpenCV_INCLUDE_DIRS}")