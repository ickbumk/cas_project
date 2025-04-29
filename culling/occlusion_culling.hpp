#ifndef OCCLUSION_CULLING_H
#define OCCLUSION_CULLING_H


#include <vector>
#include <array>
#include <iostream>

/* struct Face{
    std::vector<int> ind_vertex;
    std::vector<int> ind_texture;
    std::vector<int> ind_normal;
};
 */
class draw_face {
    public:
        draw_face(int width, int height) : width(width), height(height) {
            frame_buffer = std::vector<std::vector<int>>(height, std::vector<int>(width, 0 ));
        }
    private:
        int width, height;
        std::vector<std::vector<int>> frame_buffer;

        void draw_triangle(const Face& face, const std::vector<std::array<float, 3>>& vertices){
            if (face.ind_vertex.size() != 3){
                std::cerr<< "Error: A face must have 3 vertices! " << std::endl;
                return;
            }

            std::array<float,3> v0 = vertices[face.ind_vertex[0]];
            std::array<float,3> v1 = vertices[face.ind_vertex[1]];
            std::array<float,3> v2 = vertices[face.ind_vertex[2]];
        }

};

#endif