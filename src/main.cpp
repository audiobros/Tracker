#include <iostream>

#include <tracktion_engine/tracktion_engine.h>


int main(){
  std::unique_ptr<juce::ScopedJuceInitialiser_GUI> initializer = std::make_unique<juce::ScopedJuceInitialiser_GUI>();
  std::unique_ptr<tracktion::Engine> engine = std::make_unique<tracktion::Engine>("TrackerBro");

  std::cout << "Here!, congrats!" << std::endl;

  return 0;
}
