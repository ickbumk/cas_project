add_library(culling cameraProperties.cpp)

target_include_directories(culling PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS})

target_link_libraries(culling PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS} ${OpenCV_LIBS})

target_link_libraries(culling PRIVATE utils)

