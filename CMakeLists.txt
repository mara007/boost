cmake_minimum_required(VERSION 3.16)
project(boost_tester)


add_subdirectory(ranges)


add_executable(boost_tester main.cpp)
#target_include_directories(boost_tester)

find_package(Boost 1.71.0)
target_link_libraries(boost_tester
    #ranges
    
    ${Boost_LIBRARIES})