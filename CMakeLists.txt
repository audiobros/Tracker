cmake_minimum_required(VERSION 3.25)

# Set project name
project(tracker VERSION 1.0 LANGUAGES CXX)

# If we are compiling for macOS we want to target OS versions down to 11.0
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror")

##########
## Test ##
##########
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/Catch2 ./cmake_build_catch2)
set(SourceFiles
    src/test/PlayerTest.cpp
    src/test/TickerTest.cpp
    src/Player/Player.cpp
    src/Player/Player.h
    src/Player/Ticker.cpp
    src/Player/Ticker.h)

# These tests can use the Catch2-provided main
add_executable(tests ${SourceFiles})
#add_executable(tests src/test/SetupTest.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

