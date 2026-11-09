#pragma once

#include <string>
#include <vector>

namespace speechsight::vision {

struct Point2D {
    float x {};
    float y {};
};

struct FrameLandmarks {
    int frame_index {};
    std::vector<Point2D> lip_points {};
    std::vector<Point2D> face_outline {};
    float mouth_openness {};
};

class LandmarkTracker {
  public:
    std::vector<FrameLandmarks> track(const std::string& video_path) const;
};

}  // namespace speechsight::vision

