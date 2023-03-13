cmake_minimum_required(VERSION 3.23.2)

# Set project name
project(TRACKER_PROJECT VERSION 1.0 LANGUAGES CXX)

# If we are compiling for macOS we want to target OS versions down to 10.11
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror")

# Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules/juce ${CMAKE_BINARY_DIR}/tracktion/juce)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules ${CMAKE_BINARY_DIR}/tracktion)

juce_add_console_app(TrackerBro PRODUCT_NAME "TrackerBro App")
target_sources(TrackerBro
    PUBLIC
        src/main.cpp)
juce_generate_juce_header(TrackerBro)

add_library(tracktion STATIC)
target_include_directories(tracktion INTERFACE ${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules
                                               ${CMAKE_CURRENT_LIST_DIR}/external/tracktion_engine/modules/juce)
target_link_libraries(tracktion 
    PUBLIC 
        tracktion::tracktion_core
        tracktion::tracktion_engine
        tracktion::tracktion_graph
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

target_compile_definitions(TrackerBro
    PRIVATE
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_console_app` call
        JUCE_USE_CURL=0)    # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_console_app` call

target_link_libraries(TrackerBro 
    PUBLIC
        tracktion
)