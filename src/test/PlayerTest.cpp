/// PlayerTest.cpp

#include <catch2/catch_test_macros.hpp>
#include "../../src/Player/Player.h"

TEST_CASE("Make Player", "[player]" )
{
    Player player;
    REQUIRE(true);
}

TEST_CASE("Process all samples", "[player]")
{
    Player player;
    float samples[10] {0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f};
    int size = sizeof(samples)/(sizeof(float));
    player.processBuffer(samples, size);
    
    for (int i = 0; i < size; i++) {
        REQUIRE(samples[i] == 1.0f);
    }
}

TEST_CASE("Process 8 samples, leave 2 untouched", "[player]")
{
    Player player;
    float samples[10] {0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f};
    int size = sizeof(samples)/(sizeof(float));
    player.processBuffer(samples, 8);
    
    REQUIRE(samples[8] != 1.0f);
    REQUIRE(samples[9] != 1.0f);
}
