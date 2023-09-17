/// Ticker.h

#include <vector>

class Ticker {
    
public:
    class Listener {
    public:
        Listener() {};
        virtual ~Listener() {};
        virtual void handleTick() = 0;
    };
   
    //==============================================================================
    Ticker(int tickSpeed);
    
    void processSample();
    
    void setTickSpeed(int tickSpeed);
    int getTickSpeed();
   
    //==============================================================================
    void addListener(Listener* listener);
    void removeListener(Listener* listener);
    
private:
    std::vector<Ticker::Listener*> mListeners;
    
    int mNumSamples;
    int mTickSpeed;
};
