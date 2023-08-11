/// Player.cpp

#include "Player.h"

Player::Player() : mTicker(Ticker(TICKSPEED))
{
    mTicker.addListener(*this);
}

Player::~Player()
{
    mTicker.removeListener(*this);
}

void Player::processBuffer(int samples)
{
    for (int i = 0; i < samples; i++)
        mTicker.processSample();
}

void Player::progressRow(int samples)
{
    std::cout << "Starting next row..." << std::endl;
}

void Player::processTick()
{
    if (mTicksPerLine == mTickCount) {
        mTickCount = 0;
    }
    progressRow();
}

void Player::setTicksPerLine(int ticksPerLine)
{
    mTicksPerLine = ticksPerLine;
}

void Player::getTicksPerLine(int ticksPerLine)
{
    return mTicksPerLine;
}
