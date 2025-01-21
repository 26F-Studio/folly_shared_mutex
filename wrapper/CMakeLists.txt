cmake_minimum_required(VERSION 3.28)

project(shared_mutex_wrapper C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/fetch_boost.cmake)