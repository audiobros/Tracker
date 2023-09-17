/// Player.cpp

#include "Ticker.h"
#include "Pattern.h"
#include <vector>


#define TICKSPEED 10000

class Player {
public:
    Player();
    ~Player();
    
    //==============================================================================
    void processBuffer(int samples);
    void progressRow();
    
    // Ticker::Listener Overrides
//    void handleTick() override;
    
    //==============================================================================
    void setTicksPerLine(int ticksPerLine);
    void getTicksPerLine(int ticksPerLine);
    
    //==============================================================================
    void insertPattern(Pattern& pattern);
    
private:
    std::vector<Pattern> mPatterns;
    
    Ticker mTicker;
    int mTickCount;
    int mTicksPerLine;
};
