# Midterm Report

## Introduction

Occlusion culling is a critical optimization technique in computer graphics and game development, improving rendering efficiency by discarding objects that are not visible to the camera. This report details the progress made in implementing occlusion culling pipeline in C++.

## Project Scope and Objectives
Goal of this project is to develop an efficient occlusion culling algorithm in C++ and make it more accessible to git users. Although occlusion and backface culling is widely used in computer vision and 3D graphics, open source repository is not available. Therefore, this project aims to introduce simple implementation of occlusion culling, including the followinig key objectives:
- Implementing backface culling by using surface normal and camera extrinsic matrix
- Iteratively render image plane using surface metadata and occlusion culling
- Optimizing with multi-threading for real-time performance (optional, depending on successful implementation of the two previously mentioned objectives)


## Current Development Progress
The development process can be subdivided into the following phases. Following project has already been implemented in Python. Extensive translation into C++ is being undertaken:

1. Phase 1: Dataset Acquisition
- Adequate point cloud dataset (PCD) needs to be investigated for robust benchmarking
- PCD should contain necessary data to avoid over-expanding the scope of the project

2. Phase 2: Code Development (Ongoing)
- Efficient C++ implementation
- Modular coding for easier testing
- Unittest construction

3. Phase 3: Performance Enhancement and Optimization (Optional)
- Multi-threading
- GPU implementation 
- Reducing memory usage 

## Conclusion
Significant progress has been made in implementing occlusion culling. However, major translation to C++ needs to be done as it was primarily coded in Python. The current memory and time consumption is not very high but needs improvement. C++ implementation will definitely help in optimizing and introduce the opportunity for multi-threading and GPU utilization. 

Preliminary results from python can be found in current folder with:
- mvs.png 
- occlusion culling.png 
