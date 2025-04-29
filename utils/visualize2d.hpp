#ifndef VISUALIZE2D_H
#define VISUALIZE2D_H

#include <string>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

void writeImage(const cv::Mat& image, const std::string& windowName = "Image");

#endif