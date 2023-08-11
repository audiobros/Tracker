/// Player.cpp

#include "Ticker.h"


#define TICKSPEED 10000

class Player : public Ticker::Listener {
public:
    Player();
    ~Player();
    
    //==============================================================================
    void processBuffer(int samples);
    void progressRow();
    
    // Ticker::Listener Overrides
    void processTick() override;
    
    //==============================================================================
    void setTicksPerLine(int ticksPerLine);
    void getTicksPerLine(int ticksPerLine);
    
private:
    Ticker mTicker;
    int mTickCount;
    int mTicksPerLine;
};
