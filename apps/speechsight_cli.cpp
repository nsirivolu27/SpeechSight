#include <iostream>
#include <string>

#include "core/Pipeline.h"

int main(int argc, char** argv) {
    std::string audio_path = argc > 2 ? argv[2] : "sample.wav";
    std::string video_path = argc > 4 ? argv[4] : "sample.mp4";

    speechsight::core::Pipeline pipeline;
    const auto result = pipeline.run(audio_path, video_path);

    std::cout << "SpeechSight analysis complete\n";
    std::cout << "Detected phoneme windows: " << result.phonemes.size() << "\n";
    std::cout << "Tracked video frames: " << result.landmarks.size() << "\n\n";

    for (std::size_t i = 0; i < result.phonemes.size() && i < 8; ++i) {
        const auto& phoneme = result.phonemes[i];
        std::cout << "[" << phoneme.timestamp_seconds << "s] "
                  << phoneme.phoneme << " (" << phoneme.confidence << ")\n";
    }

    std::cout << "\n" << result.heatmap << "\n";
    return 0;
}
