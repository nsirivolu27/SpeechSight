#pragma once

#include <vector>

namespace speechsight::audio {

struct AudioFrame {
    double timestamp_seconds {};
    std::vector<float> samples {};
};

}  // namespace speechsight::audio

