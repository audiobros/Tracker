/// Ticker.cpp

#include <Player/Ticker.h>
#include <algorithm>

Ticker::Ticker(int samplesPerTick) : mSamplesPerTick(samplesPerTick),
    mTicksPerRow(0),
    mSampleAccumulator(0),
    mCurrentTick(0),
    mCurrentRow(0)
{
}

//==============================================================================
void Ticker::processSample()
{
    mSampleAccumulator++;
    if (mSampleAccumulator == mSamplesPerTick)
    {
        if (++mCurrentTick == mTicksPerRow) {
            mCurrentRow++;
            mCurrentTick = 0;
        }
        mSampleAccumulator = 0;
    }
}

//==============================================================================
void Ticker::setTickSpeed(int samplesPerTick)
{
    mSamplesPerTick = samplesPerTick;
}

int Ticker::getTickSpeed()
{
    return mSamplesPerTick;
}

int Ticker::getCurrentTick()
{
    return mCurrentTick;
}

//==============================================================================
void Ticker::setTicksPerRow(int ticksPerRow)
{
    mTicksPerRow = ticksPerRow;
}

int Ticker::getTicksPerRow()
{
    return mTicksPerRow;
}

int Ticker::getCurrentRow()
{
    return mCurrentRow;
}
