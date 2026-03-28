# SpeechSight

SpeechSight is a C++ speech analysis project that combines a real-time phoneme recognition pipeline with facial and lip movement tracking. The repo is structured to reflect the work described on my resume:

- audio feature extraction and phoneme inference pipeline
- computer vision modules for lip and facial landmark tracking
- heatmap generation for speech-pattern visualization

## Highlights

- Real-time style audio frame processing with MFCC-like feature extraction
- Pluggable phoneme recognition interface inspired by Kaldi and TensorFlow workflows
- OpenCV and dlib-ready vision pipeline abstractions
- Visual heatmap output for lip movement intensity over time

## Project Layout

```text
include/
  audio/
  vision/
  core/
src/
  audio/
  vision/
  core/
apps/
  speechsight_cli.cpp
```

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Example Usage

```bash
./build/SpeechSightCLI --audio sample.wav --video sample.mp4
```

## Notes

This repo uses lightweight internal implementations and interfaces so the project is easy to share publicly. It is designed to be extended with real Kaldi, TensorFlow, OpenCV, and dlib integrations when needed.

