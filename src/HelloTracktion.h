//
//  HelloWorld.hpp
//  tracker
//
//  Created by Sercan Atlı on 24/03/2023.
//

#pragma once

#include <stdio.h>
#include <tracktion_engine/tracktion_engine.h>


class HelloTracktion {
public:
    HelloTracktion();
    ~HelloTracktion();
    
    void initializeEngine();
    
    tracktion::WaveAudioClip::Ptr loadTestClip();
    
    std::string sayHello();
    void loopSampleAudio();

private:
    
    // Things I scrapped from Tracktion examples
    inline tracktion::AudioTrack* getOrInsertAudioTrackAt (tracktion::Edit& edit, int index)
    {
        edit.ensureNumberOfAudioTracks (index + 1);
        return tracktion::getAudioTracks (edit)[index];
    }
    
    inline tracktion::WaveAudioClip::Ptr loadAudioFileAsClip (tracktion::Edit& edit, const juce::File& file)
    {
        // Find the first track and delete all clips from it
        if (auto track = getOrInsertAudioTrackAt (edit, 0))
        {
            removeAllClips (*track);

            // Add a new clip to this track
            tracktion::AudioFile audioFile (edit.engine, file);

            if (audioFile.isValid())
                if (auto newClip = track->insertWaveClip (file.getFileNameWithoutExtension(), file,
                                                          { { {}, tracktion::TimeDuration::fromSeconds (audioFile.getLength()) }, {} }, false))
                    return newClip;
        }

        return {};
    }
    
    inline void removeAllClips (tracktion::AudioTrack& track)
    {
        auto clips = track.getClips();

        for (int i = clips.size(); --i >= 0;)
            clips.getUnchecked (i)->removeFromParentTrack();
    }
    
    std::unique_ptr<tracktion::Engine> mEngine;
    std::unique_ptr<tracktion::Edit> mEdit;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloTracktion)
};
