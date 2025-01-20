cmake_minimum_required(VERSION 3.28p)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(folly_shared_mutex C CXX)

add_library(${PROJECT_NAME})

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/fetch_boost.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/fetch_fmt.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/fetch_glog.cmake)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/folly-config.h.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/folly/folly-config.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Boost::preprocessor
        fmt::fmt
        glog::glog)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly ROOT_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/concurrency CONCURRENCY_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/detail DETAIL_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/hash HASH_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/lang LANG_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/memory MEMORY_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/memory/detail MEMORY_DETAIL_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/portability PORTABILITY_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/synchronization SYNC_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/folly/system SYSTEM_SRC)

target_sources(${PROJECT_NAME} PRIVATE
        ${ROOT_SRC}
        ${CONCURRENCY_SRC}
        ${DETAIL_SRC}
        ${HASH_SRC}
        ${LANG_SRC}
        ${MEMORY_SRC}
        ${MEMORY_DETAIL_SRC}
        ${PORTABILITY_SRC}
        ${SYNC_SRC}
        ${SYSTEM_SRC})
