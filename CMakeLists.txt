cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT") 
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
project(testFilter)
add_subdirectory(myFilterLib)
add_subdirectory(googletest)
set(SOURCES testFilter.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} myfilter gtest)
