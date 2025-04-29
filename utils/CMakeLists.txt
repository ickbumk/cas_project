add_library(utils read_obj.cpp visualize2d.cpp)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS})

target_link_libraries(utils PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS} ${OpenCV_LIBS})

