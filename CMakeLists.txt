cmake_minimum_required(VERSION 3.20)
project(SpeechSight LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(speechsight_core
    src/audio/AudioFrame.cpp
    src/audio/FeatureExtractor.cpp
    src/audio/PhonemeRecognizer.cpp
    src/vision/LandmarkTracker.cpp
    src/vision/HeatmapGenerator.cpp
    src/core/Pipeline.cpp
)

target_include_directories(speechsight_core PUBLIC include)

add_executable(SpeechSightCLI apps/speechsight_cli.cpp)
target_link_libraries(SpeechSightCLI PRIVATE speechsight_core)

