add_library(utils read_obj.cpp)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(utils PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})