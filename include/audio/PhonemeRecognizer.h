#pragma once

#include <string>
#include <vector>

#include "audio/FeatureExtractor.h"

namespace speechsight::audio {

struct PhonemePrediction {
    double timestamp_seconds {};
    std::string phoneme {};
    float confidence {};
};

class PhonemeRecognizer {
  public:
    std::vector<PhonemePrediction> infer(const std::vector<AudioFeatures>& features) const;
};

}  // namespace speechsight::audio

