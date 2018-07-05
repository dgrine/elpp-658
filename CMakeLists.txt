cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 14)

project(elpp)
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/easylogging++.cc")
add_library(elpp STATIC ${SOURCES})
# Enable this define for the 'expected' behavior
target_compile_definitions(elpp PRIVATE ELPP_ISSUE_X)

project(app)
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
add_executable(app ${SOURCES})
target_link_libraries(app PRIVATE elpp)

