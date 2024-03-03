/// Ticker.h

#include <vector>

class Ticker {
    
public:
    //==============================================================================
    Ticker(int samplesPerTick);
   
    //==============================================================================
    void processSample();
   
    //==============================================================================
    void setTickSpeed(int samplesPerTick);
    int getTickSpeed();
    int getCurrentTick();
    
    //==============================================================================
    void setTicksPerRow(int ticksPerRow);
    int getTicksPerRow();
    int getCurrentRow();
   
private:
    int mSamplesPerTick;
    int mTicksPerRow;
    
    int mSampleAccumulator;
    int mCurrentTick;
    int mCurrentRow;
};
