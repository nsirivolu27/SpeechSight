#include "audio/FeatureExtractor.h"

#include <cmath>
#include <numeric>

namespace speechsight::audio {

AudioFeatures FeatureExtractor::extract(const AudioFrame& frame) const {
    AudioFeatures features {};
    features.timestamp_seconds = frame.timestamp_seconds;

    if (frame.samples.empty()) {
        features.coefficients = std::vector<float>(13, 0.0F);
        return features;
    }

    float energy_sum = 0.0F;
    int zero_crossings = 0;

    for (std::size_t i = 0; i < frame.samples.size(); ++i) {
        const float sample = frame.samples[i];
        energy_sum += sample * sample;

        if (i > 0) {
            const bool crossed = (frame.samples[i - 1] >= 0.0F && sample < 0.0F) ||
                                 (frame.samples[i - 1] < 0.0F && sample >= 0.0F);
            if (crossed) {
                ++zero_crossings;
            }
        }
    }

    features.energy = std::sqrt(energy_sum / static_cast<float>(frame.samples.size()));
    features.zero_crossing_rate = static_cast<float>(zero_crossings) / static_cast<float>(frame.samples.size());

    features.coefficients.reserve(13);
    const float mean = std::accumulate(frame.samples.begin(), frame.samples.end(), 0.0F) /
                       static_cast<float>(frame.samples.size());

    for (int band = 0; band < 13; ++band) {
        float accumulator = 0.0F;
        for (std::size_t i = 0; i < frame.samples.size(); ++i) {
            accumulator += std::abs(frame.samples[i] - mean) * static_cast<float>((band + 1) * (i % 7 + 1));
        }
        features.coefficients.push_back(accumulator / static_cast<float>(frame.samples.size() * (band + 1)));
    }

    return features;
}

}  // namespace speechsight::audio

