#include "vision/HeatmapGenerator.h"

#include <algorithm>
#include <sstream>

namespace speechsight::vision {

std::string HeatmapGenerator::render_ascii_heatmap(const std::vector<FrameLandmarks>& frames) const {
    std::ostringstream out;
    out << "Lip Motion Heatmap\n";
    out << "------------------\n";

    for (const auto& frame : frames) {
        const int bars = std::clamp(static_cast<int>(frame.mouth_openness * 20.0F), 1, 20);
        out << "Frame " << frame.frame_index << " ";
        for (int i = 0; i < bars; ++i) {
            out << '#';
        }
        out << '\n';
    }

    return out.str();
}

}  // namespace speechsight::vision

