#pragma once

#include <string>
#include <vector>

#include "audio/AudioFrame.h"
#include "audio/FeatureExtractor.h"
#include "audio/PhonemeRecognizer.h"
#include "vision/HeatmapGenerator.h"
#include "vision/LandmarkTracker.h"

namespace speechsight::core {

struct PipelineResult {
    std::vector<audio::PhonemePrediction> phonemes {};
    std::vector<vision::FrameLandmarks> landmarks {};
    std::string heatmap {};
};

class Pipeline {
  public:
    Pipeline();

    PipelineResult run(const std::string& audio_path, const std::string& video_path) const;

  private:
    std::vector<audio::AudioFrame> load_audio_frames(const std::string& audio_path) const;

    audio::FeatureExtractor feature_extractor_;
    audio::PhonemeRecognizer phoneme_recognizer_;
    vision::LandmarkTracker landmark_tracker_;
    vision::HeatmapGenerator heatmap_generator_;
};

}  // namespace speechsight::core
