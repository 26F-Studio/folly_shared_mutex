include(FetchContent)

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmake/fmt-11.0.2.zip")
    FetchContent_Declare(
            fmt
            URL file://${CMAKE_CURRENT_SOURCE_DIR}/cmake/fmt-11.0.2.zip
    )
else ()
    FetchContent_Declare(
            fmt
            GIT_REPOSITORY https://github.com/fmtlib/fmt.git
            GIT_TAG 11.0.2
    )
endif ()

FetchContent_MakeAvailable(fmt)