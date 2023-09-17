cmake_minimum_required(VERSION 3.25)

# Set project name
project(tracker VERSION 1.0 LANGUAGES Swift OBJC CXX)

if(IOS)
  set(CMAKE_OSX_DEPLOYMENT_TARGET "15.0" CACHE INTERNAL "")
else()
  set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0" CACHE INTERNAL "")
endif()

# If we are compiling for macOS we want to target OS versions down to 11.0
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror")

# Swift related settings
set(CMAKE_Swift_LANGUAGE_VERSION 5)

# Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)
option(JUCE_BUILD_EXTRAS "Build JUCE Examples" OFF)
option(JUCE_BUILD_EXAMPLES "Build JUCE Extras" OFF)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules/juce)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules ./cmake_build_tracktion)

###############################
# Create Tracktion Static Lib #
###############################
add_library(Tracktion STATIC)
target_include_directories(Tracktion PRIVATE ${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules
                                            ${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules/juce)
target_link_libraries(Tracktion 
  PRIVATE
        tracktion::tracktion_core
        tracktion::tracktion_engine
        tracktion::tracktion_graph)

#########################
# Create Tracker Target #
#########################
juce_add_console_app(tracker MACOSX_BUNDLE)
set(SourceFiles       
        src/Player/Player.cpp
        src/Player/Player.h
        src/Player/Ticker.cpp
        src/Player/Ticker.h
        src/Player/Pattern.cpp
        src/Player/Pattern.h
        src/Player/ChannelData.h
        src/HelloTracktion.cpp
        src/HelloTracktion.h
        src/HelloTracktionWrapper.h
        src/HelloTracktionWrapper.mm
        src/tracker-Bridging-Header.h
        src/ContentView.swift
        src/trackerUI.swift)
        
target_sources(tracker PRIVATE ${SourceFiles})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/.. FILES ${SourceFiles})
target_include_directories(tracker PRIVATE ${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules)
target_include_directories(tracker PRIVATE ${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules/juce/modules)
target_link_libraries(tracker PRIVATE Tracktion)

set_target_properties(tracker PROPERTIES
  XCODE_ATTRIBUTE_SWIFT_OBJC_BRIDGING_HEADER "${PROJECT_SOURCE_DIR}/src/tracker-Bridging-Header.h"
  XCODE_ATTRIBUTE_SWIFT_OPTIMIZATION_LEVEL "-Onone"
  XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2"
  MACOSX_BUNDLE_BUNDLE_NAME "Tracker"
  MACOSX_BUNDLE_BUNDLE_VERSION "1.0.0"
  MACOSX_BUNDLE_GUI_IDENTIFIER "TrackerBro"
  MACOSX_BUNDLE_LONG_VERSION_STRING "1.0.0"
  MACOSX_BUNDLE_SHORT_VERSION_STRING "1"
)
set_property(TARGET tracker PROPERTY CXX_STANDARD 17)

target_compile_definitions(tracker
    PRIVATE
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_console_app` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_console_app` call
        JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED=1)  # We don't need a global header


##########
## Test ##
##########

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/Catch2 ./cmake_build_catch2)
# These tests can use the Catch2-provided main
add_executable(tests src/test/SetupTest.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

