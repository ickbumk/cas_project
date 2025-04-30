#include <string>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include "read_obj.hpp"
#include "mathUtils.hpp"

// Writes image to a file
void writeImage(const cv::Mat& image, const std::string& filename = "Image.png") {
    if (image.empty()) {
        std::cerr << "Error: Provided image is empty." << std::endl;
        return;
    }

    cv::imwrite(filename, image);
}

// Draws triangles onto the image using vertex and face data
void drawTriangle(cv::Mat& image, const std::vector<Triangle>& triangles,std::vector<double> facedistances, std::vector<int> sortedIndices){
    if (image.empty()) {
        std::cerr << "Error: Provided image is empty." << std::endl;
        return;
    }
    
    int i = 0;
    double maxDistance = maxValue(facedistances);
    double minDistance = minValue(facedistances);
    for (const auto& triangle : triangles) {

        
        // Convert Vec2Int to cv::Point
        cv::Point a(triangle.a[0].u, triangle.a[0].v);
        cv::Point b(triangle.b[0].u, triangle.b[0].v);
        cv::Point c(triangle.c[0].u, triangle.c[0].v);

        cv::fillPoly(image, std::vector<std::vector<cv::Point>>{ { a, b, c } }, cv::Scalar((facedistances[sortedIndices[i]]-minDistance)/maxDistance*255)); // Fill the triangle with a color based on distance

        i += 1;
    }
}
    
