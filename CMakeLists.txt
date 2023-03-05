cmake_minimum_required(VERSION 3.25)

# Set project name
project(tracker VERSION 1.0 LANGUAGES CXX)

# Set Binary Dir in project
set(CMAKE_BINARY_DIR build/bin)

add_executable(tracker main.cpp)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules/juce ${CMAKE_BINARY_DIR}/tracktion/juce EXCLUDE_FROM_ALL)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules ${CMAKE_BINARY_DIR}/tracktion EXCLUDE_FROM_ALL)

add_library(tracktion STATIC)

target_link_libraries(tracktion 
  PRIVATE
        tracktion::tracktion_core
        tracktion::tracktion_engine
        tracktion::tracktion_graph
  PUBLIC 
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

target_link_libraries(tracker tracktion)
