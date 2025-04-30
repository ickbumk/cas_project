#ifndef CAMERA_PROPERTIES_H
#define CAMERA_PROPERTIES_H
#include <opencv2/opencv.hpp>

cv::Mat getSampleIntrinsicMatrix();
cv::Mat getLookAtRT(const cv::Vec3d& eye, const cv::Vec3d& target, const cv::Vec3d& up);
cv::Mat projectPoints(const std::vector<Vec3>& points, const cv::Mat& projectionMatrix);

#endif
