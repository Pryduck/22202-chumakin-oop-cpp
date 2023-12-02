project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()
add_executable(
        Google_Tests_run
        Parser_test.cpp
        Statistic_test.cpp
        FileReader_test.cpp
        Writer_test.cpp
        ../Parser.h
        ../Parser.cpp
        ../Statistic.h
        ../Statistic.cpp
        ../FileReader.h
        ../FileReader.cpp
        ../Writer.h
        ../Writer.cpp
        ../main.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)