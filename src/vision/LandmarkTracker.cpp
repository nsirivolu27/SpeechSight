#include "vision/LandmarkTracker.h"

#include <cmath>

namespace speechsight::vision {

std::vector<FrameLandmarks> LandmarkTracker::track(const std::string& video_path) const {
    std::vector<FrameLandmarks> frames;
    const int frame_count = video_path.empty() ? 0 : 24;
    frames.reserve(frame_count);

    for (int i = 0; i < frame_count; ++i) {
        FrameLandmarks frame {};
        frame.frame_index = i;
        frame.mouth_openness = 0.35F + 0.25F * std::sin(static_cast<float>(i) * 0.4F);

        for (int p = 0; p < 12; ++p) {
            const float angle = static_cast<float>(p) * 0.52F;
            frame.lip_points.push_back({
                50.0F + 12.0F * std::cos(angle),
                50.0F + (8.0F + frame.mouth_openness * 10.0F) * std::sin(angle)
            });
        }

        frame.face_outline = {
            {28.0F, 25.0F}, {72.0F, 25.0F}, {80.0F, 50.0F},
            {72.0F, 78.0F}, {28.0F, 78.0F}, {20.0F, 50.0F}
        };

        frames.push_back(frame);
    }

    return frames;
}

}  // namespace speechsight::vision

