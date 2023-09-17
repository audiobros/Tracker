/// Player.cpp

#include "Player.h"
#include <iostream>

Player::Player() : mTicker(Ticker(TICKSPEED))
{
    mTicker.addListener(*this);
    mPatterns.push_back(Pattern());
}

Player::~Player()
{
    mTicker.removeListener(*this);
}

//==============================================================================
void Player::processBuffer(int samples)
{
    for (int i = 0; i < samples; i++)
        mTicker.processSample();
}

void Player::progressRow()
{
    std::cout << "Starting next row..." << std::endl;
}

void Player::handleTick()
{
    if (mTicksPerLine == mTickCount) {
        mTickCount = 0;
    }
    progressRow();
}

//==============================================================================
void Player::setTicksPerLine(int ticksPerLine)
{
    mTicksPerLine = ticksPerLine;
}

void Player::getTicksPerLine(int ticksPerLine)
{
    return mTicksPerLine;
}

//==============================================================================
void Player::insertPattern(Pattern& pattern)
{
    mPatterns.push_back(pattern);
}
