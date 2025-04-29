#include <string>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include "read_obj.hpp"

// Writes image to a file
void writeImage(const cv::Mat& image, const std::string& filename = "Image.png") {
    if (image.empty()) {
        std::cerr << "Error: Provided image is empty." << std::endl;
        return;
    }

    cv::imwrite(filename, image);
}

// Draws triangles onto the image using vertex and face data
void drawTriangle(cv::Mat& image, const std::vector<Vec3>& vertices, const std::vector<Face>& faces) {
    for (const auto& face : faces) {
        if (face.ind_vertex.size() < 3) continue;

        std::vector<cv::Point> points;
        for (int i = 0; i < 3; ++i) {
            int idx = face.ind_vertex[i] - 1;  // OBJ is 1-based
            if (idx >= 0 && idx < vertices.size()) {
                points.emplace_back(
                    static_cast<int>(vertices[idx].x),
                    static_cast<int>(vertices[idx].y)
                );
            }
        }

        if (points.size() == 3) {
            cv::Scalar color(255);  // white for grayscale
            cv::fillConvexPoly(image, points, color);
        }
    }
}
