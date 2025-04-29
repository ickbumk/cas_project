cmake_minimum_required(VERSION 3.10)
project(OcclusionCulling CXX)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2 # or the latest version you want
)

FetchContent_MakeAvailable(Catch2)

find_package(Catch2 CONFIG REQUIRED)

add_subdirectory(utils)
add_subdirectory(tests)

add_executable(main main.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(main PUBLIC utils)