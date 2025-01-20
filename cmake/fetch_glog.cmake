include(FetchContent)

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmake/glog-0.5.0.zip")
    FetchContent_Declare(
            glog
            URL file://${CMAKE_CURRENT_SOURCE_DIR}/cmake/glog-0.5.0.zip
    )
else ()
    FetchContent_Declare(
            glog
            GIT_REPOSITORY https://github.com/google/glog.git
            GIT_TAG v0.5.0
    )
endif ()

FetchContent_MakeAvailable(glog)