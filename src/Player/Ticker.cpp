///Ticker.cpp

#include "Ticker.h"
#include <algorithm>

Ticker::Ticker(int tickSpeed) : mTickSpeed(tickSpeed)
{
    
}

//==============================================================================
void Ticker::processSample()
{
    mNumSamples++;
    if (++mNumSamples == mTickSpeed) {
        std::for_each(mListeners.begin(), mListeners.end(), [](auto& listener) { listener.handleTick(); });
        mNumSamples = 0;
    }
}

void Ticker::setTickSpeed(int tickSpeed)
{
    mTickSpeed = tickSpeed;
}

int Ticker::getTickSpeed()
{
    return mTickSpeed;
}

//==============================================================================
void Ticker::addListener(const Listener& listener)
{
    mListeners.push_back(listener);
}

void Ticker::removeListener(const Listener& listener)
{
    auto itr = std::find(mListeners.begin(), mListeners.end(), listener);
    
    if (itr != mListeners.end())
        mListeners.erase(itr);
}
