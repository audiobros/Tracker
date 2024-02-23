/// Player.cpp

#include <Player/Player.h>
#include <iostream>

Player::Player()
{
}

Player::~Player()
{
}

//==============================================================================
void Player::processBuffer(float* buffer, int samples)
{
    for (int i = 0; i < samples; i ++) {
        buffer[i] = 1.0f;
    }
}
