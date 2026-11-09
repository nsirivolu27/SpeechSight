#include "audio/PhonemeRecognizer.h"

#include <array>

namespace speechsight::audio {

std::vector<PhonemePrediction> PhonemeRecognizer::infer(const std::vector<AudioFeatures>& features) const {
    static constexpr std::array<const char*, 8> phoneme_bank = {"AH", "EH", "IH", "OH", "OO", "S", "T", "M"};

    std::vector<PhonemePrediction> predictions;
    predictions.reserve(features.size());

    for (const auto& feature : features) {
        const float signature = feature.energy * 100.0F + feature.zero_crossing_rate * 10.0F +
                                (feature.coefficients.empty() ? 0.0F : feature.coefficients.front());
        const auto index = static_cast<std::size_t>(static_cast<int>(signature) % phoneme_bank.size());

        PhonemePrediction prediction {};
        prediction.timestamp_seconds = feature.timestamp_seconds;
        prediction.phoneme = phoneme_bank[index];
        prediction.confidence = 0.7F + (feature.energy > 0.15F ? 0.18F : 0.08F);
        predictions.push_back(prediction);
    }

    return predictions;
}

}  // namespace speechsight::audio

