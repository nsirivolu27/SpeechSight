#pragma once

#include <string>
#include <vector>

#include "vision/LandmarkTracker.h"

namespace speechsight::vision {

class HeatmapGenerator {
  public:
    std::string render_ascii_heatmap(const std::vector<FrameLandmarks>& frames) const;
};

}  // namespace speechsight::vision

