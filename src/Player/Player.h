/// Player.cpp

#include <vector>


#define TICKSPEED 10000

class Player {
public:
    Player();
    ~Player();
    
    //==============================================================================
    void processBuffer(float* buffer, int samples);
};
