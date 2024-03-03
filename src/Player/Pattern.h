//
//  Pattern.h
//  Tracktion
//
//  Created by Brian Arne on 6/2/23.
//

#pragma once
#include <vector>
#include <Player/ChannelData.h>

    
class Pattern {
public:
    Pattern();
    ~Pattern();
    
    
private:
    std::vector<ChannelData> mRow;
    int currentRow;
};
