#ifndef OCCLUSION_CULLING_H
#define OCCLUSION_CULLING_H


#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

class draw_face {
    public:
        draw_face(int width, int height) : width(width), height(height) {
            frame_buffer = std::vector<std::vector<std::array<int, 3>>> ()
        }
    private:
        int width, height;
        std::vector<int> canvas;
};

#endif