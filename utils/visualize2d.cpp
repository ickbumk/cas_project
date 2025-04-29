#include <string>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include "read_obj.hpp"

// Function to visualize a 2D image using OpenCV
void writeImage(const cv::Mat& image, const std::string& windowName = "Image") {
    if (image.empty()) {
        std::cerr << "Error: Provided image is empty." << std::endl;
        return;
    }

    cv::imwrite(windowName, image);
}

void drawTriangle(const cv::Mat& image, std::vector<Vec3> vertices, const cv::Scalar& color) {
    if (vertices.size() != 3) {
        std::cerr << "Error: A triangle must have exactly 3 vertices." << std::endl;
        return;
    }

    // Convert Vec3 to cv::Point
    std::vector<cv::Point> points;
    for (const auto& vertex : vertices) {
        points.emplace_back(static_cast<int>(vertex.x), static_cast<int>(vertex.y));
    }

    // Draw the triangle
    cv::fillConvexPoly(image, points, color);
}


