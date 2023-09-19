/// TickerTest.cpp

#include <catch2/catch_test_macros.hpp>

#include "../../src/Player/Ticker.h"

TEST_CASE("Create Ticker", "[Ticker]")
{
    Ticker ticker(10);
    REQUIRE(true);
}

TEST_CASE("Set Tick Speed", "[Ticker]")
{
    Ticker ticker(100);
    REQUIRE(ticker.getTickSpeed() == 100);
    ticker.setTickSpeed(500);
    REQUIRE(ticker.getTickSpeed() == 500);
}

TEST_CASE("Tick 5 Times", "[Ticker]")
{
    Ticker ticker(100);
    REQUIRE(ticker.getCurrentTick() == 0);
    for (int i = 0; i < 500; i++) {
        ticker.processSample();
    }
    REQUIRE(ticker.getCurrentTick() == 5);
    for (int i = 0; i < 500; i++) {
        ticker.processSample();
    }
    REQUIRE(ticker.getCurrentTick() != 5);
}

TEST_CASE("Get Current Row", "[Ticker]")
{
    Ticker ticker(100);
    ticker.setTicksPerRow(3);
    REQUIRE(ticker.getCurrentRow() == 0);
   
    for (int i = 0; i < 500; i++) {
        ticker.processSample();
    }
    REQUIRE(ticker.getCurrentRow() == 1);
    for (int i = 0; i < 500; i++) {
        ticker.processSample();
    }
    REQUIRE(ticker.getCurrentRow() == 3);
}

