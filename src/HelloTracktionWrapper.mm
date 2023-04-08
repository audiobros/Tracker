//
//  HelloTracktionWrapper.mm
//  tracker
//
//  Created by Sercan Atlı on 24/03/2023.
//

#import "HelloTracktionWrapper.h"

#import "HelloTracktion.h"

@implementation HelloTracktionWrapper {
    HelloTracktion* helloTracktion;
}

- (id)init {
    self = [super init];
    if (self)
    {
        juce::MessageManager::getInstance();
        juce::initialiseJuce_GUI();
        
        helloTracktion = new HelloTracktion();
        helloTracktion->initializeEngine();
        if (!helloTracktion) self = nil;
    }
    return self;
}

- (NSString *) sayHello {
    std::string helloWorldMessage = helloTracktion->sayHello();
    return [NSString
            stringWithCString:helloWorldMessage.c_str()
            encoding:NSUTF8StringEncoding];
}

- (void) loopTestClip {
    helloTracktion->loopSampleAudio();
}

-(void)dealloc {
    [super dealloc];
    delete helloTracktion;
}

@end
