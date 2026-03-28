#include "core/Pipeline.h"

#include <cmath>

namespace speechsight::core {

Pipeline::Pipeline() = default;

PipelineResult Pipeline::run(const std::string& audio_path, const std::string& video_path) const {
    const auto frames = load_audio_frames(audio_path);

    std::vector<audio::AudioFeatures> features;
    features.reserve(frames.size());
    for (const auto& frame : frames) {
        features.push_back(feature_extractor_.extract(frame));
    }

    PipelineResult result {};
    result.phonemes = phoneme_recognizer_.infer(features);
    result.landmarks = landmark_tracker_.track(video_path);
    result.heatmap = heatmap_generator_.render_ascii_heatmap(result.landmarks);
    return result;
}

std::vector<audio::AudioFrame> Pipeline::load_audio_frames(const std::string& audio_path) const {
    std::vector<audio::AudioFrame> frames;
    const int frame_count = audio_path.empty() ? 0 : 18;
    frames.reserve(frame_count);

    for (int i = 0; i < frame_count; ++i) {
        audio::AudioFrame frame {};
        frame.timestamp_seconds = static_cast<double>(i) * 0.02;
        frame.samples.reserve(160);

        for (int sample_index = 0; sample_index < 160; ++sample_index) {
            const float t = static_cast<float>(sample_index) / 160.0F;
            const float sample = 0.4F * std::sin(20.0F * t + static_cast<float>(i) * 0.3F) +
                                 0.15F * std::cos(11.0F * t);
            frame.samples.push_back(sample);
        }

        frames.push_back(frame);
    }

    return frames;
}

}  // namespace speechsight::core

