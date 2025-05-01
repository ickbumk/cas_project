add_executable(unit_tests unit_tests.cpp test_read.cpp test_math.cpp)

target_link_libraries(unit_tests PRIVATE Catch2::Catch2)
target_link_libraries(unit_tests PRIVATE utils)


include(CTest)
include(Catch)

catch_discover_tests(unit_tests)
