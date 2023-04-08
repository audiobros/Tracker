//
//  HelloWorld.cpp
//  tracker
//
//  Created by Sercan Atlı on 24/03/2023.
//

#include "HelloTracktion.h"

#include "PlaybackDemoAudio.h"

HelloTracktion::HelloTracktion() { }
HelloTracktion::~HelloTracktion() {
    mEngine->getTemporaryFileManager().getTempDirectory().deleteRecursively();
}

void HelloTracktion::initializeEngine() {
    mEngine = std::make_unique<tracktion::Engine>("Tracker");

    auto editFile = juce::File::createTempFile(".tracker");
    mEdit = tracktion::createEmptyEdit(*mEngine, editFile);
}

tracktion::WaveAudioClip::Ptr HelloTracktion::loadTestClip() {
    // Create test file
    auto f = juce::File::createTempFile(".ogg");
    f.replaceWithData(PlaybackDemoAudio::BITs_Export_2_ogg, PlaybackDemoAudio::BITs_Export_2_oggSize);
    
    return loadAudioFileAsClip(*mEdit, f);
}

void HelloTracktion::loopSampleAudio() {
    const auto clip = loadTestClip();
    
    // loop the test audio
    auto& transport = clip->edit.getTransport();
    transport.setLoopRange (clip->getEditTimeRange());
    transport.looping = true;

    transport.stop(false, false);
    transport.play(false);
}

std::string HelloTracktion::sayHello() {
    return "Hello from Tracktion world!";
}
