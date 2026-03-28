#pragma once

#include <vector>

#include "audio/AudioFrame.h"

namespace speechsight::audio {

struct AudioFeatures {
    double timestamp_seconds {};
    std::vector<float> coefficients {};
    float energy {};
    float zero_crossing_rate {};
};

class FeatureExtractor {
  public:
    AudioFeatures extract(const AudioFrame& frame) const;
};

}  // namespace speechsight::audio

