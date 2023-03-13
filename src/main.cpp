#include <iostream>

#include <tracktion_engine/tracktion_engine.h>


int main(){
  std::unique_ptr<juce::ScopedJuceInitialiser_GUI> initializer = std::make_unique<juce::ScopedJuceInitialiser_GUI>();
  std::unique_ptr<tracktion::Engine> engine = std::make_unique<tracktion::Engine>("TrackerBro");
  std::unique_ptr<tracktion::Edit> edit;

  const auto editFilePath = juce::JUCEApplication::getCommandLineParameters().replace ("-NSDocumentRevisionsDebugMode YES", "").unquoted().trim();
  const juce::File editFile (editFilePath);

  auto f = juce::File::createTempFile (".ogg");

  std::cout << "Here!, congrats!" << std::endl;
  return 0;
}
