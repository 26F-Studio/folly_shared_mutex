cmake_minimum_required(VERSION 3.28p)

set(PACKAGE_NAME "folly_shared_mutex")
if (NOT DEFINED PACKAGE_VERSION)
    set(PACKAGE_VERSION "0.58.0-dev")
endif ()
set(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_TARNAME "${PACKAGE_NAME}-${PACKAGE_VERSION}")

project(${PACKAGE_NAME} ASM C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED IS_X86_64_ARCH AND ${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64|AMD64")
    set(IS_X86_64_ARCH TRUE)
else()
    set(IS_X86_64_ARCH FALSE)
endif()
if(NOT DEFINED IS_AARCH64_ARCH AND ${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64")
    set(IS_AARCH64_ARCH TRUE)
else()
    set(IS_AARCH64_ARCH FALSE)
endif()

set(CMAKE_THREAD_PREFER_PTHREAD ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(FOLLY_HAVE_PTHREAD "${CMAKE_USE_PTHREADS_INIT}")
list(APPEND CMAKE_REQUIRED_LIBRARIES Threads::Threads)
list(APPEND FOLLY_LINK_LIBRARIES Threads::Threads)

add_library(${PROJECT_NAME})

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/fetch_boost.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/fetch_fmt.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/fetch_glog.cmake)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/folly-config.h.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/folly/folly-config.h
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
