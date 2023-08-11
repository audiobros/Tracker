/// Ticker.h

#include <vector>

class Ticker {
    
public:
    class Listener {
        virtual void processTick() {};
    };
    //==============================================================================
    
    Ticker(int tickSpeed);
    
    void processSample();
    
    void setTickSpeed(int tickSpeed);
    int getTickSpeed();
   
    //==============================================================================
    void addListener(const Listener& listener);
    void removeListener(const Listener& listener);
    
private:
    std::vector<Listener> mListeners;
    
    int mNumSamples;
    int mTickSpeed;
};
