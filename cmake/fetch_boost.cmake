include(FetchContent)

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmake/boost-boost-1.83.0.zip")
    FetchContent_Declare(
            Boost
            URL file://${CMAKE_CURRENT_SOURCE_DIR}/cmake/boost-boost-1.83.0.zip
    )
else ()
    FetchContent_Declare(
            Boost
            GIT_REPOSITORY https://github.com/boostorg/boost.git
            GIT_TAG boost-1.83.0
    )
endif ()

FetchContent_MakeAvailable(Boost)