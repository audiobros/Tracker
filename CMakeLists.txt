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
    src/test/PatternTest.cpp
    src/Player/Player.cpp
    src/Player/Pattern.cpp
    src/Player/Ticker.cpp)

# HeaderFiles for xcode project navigator
set(HeaderFiles
      src/Player/ChannelData.h
      src/Player/Player.h
      src/Player/Pattern.h
      src/Player/Ticker.h)

# We add HeaderFiles to executable so that .h files show in xcode project navigator
add_executable(tests ${SourceFiles} ${HeaderFiles})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# this allows us to us <> for header includes that are found in the directories below
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/includes ${CMAKE_CURRENT_SOURCE_DIR}/src)

