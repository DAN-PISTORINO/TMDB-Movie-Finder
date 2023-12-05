cmake_minimum_required(VERSION "3.27.6")
project(MF_Root C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(MINGW64_BIN "c:/msys64/mingw64/bin")
set(MINGW64_DIR "c:/msys64/mingw64")

set(FETCHCONTENT_QUIET off)
set(FETCHCONTENT_BASE_DIR "FetchContent_Downloads")

include(FetchContent)


# LIBRARIES
################
# JSON
################
FetchContent_Declare(nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_PROGRESS TRUE
  GIT_SHALLOW TRUE
  GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

add_subdirectory(ux)