#ifndef MATH_UTILS_H
#define MATH_UTILS_H
#include <cmath>
#include <iostream>
#include <vector>
#include "read_obj.hpp" 

// double maxVertexNorm(const std::vector<Vec3>& vertices);
// Vec3 avgVertex(const std::vector<Vec3>& vertices);
std::vector<Vec3> normalizeVertex(const std::vector<Vec3>& vertices);
Vec3 getCameraPosition(const cv::Mat& RT);
std::vector<double> calculateDistance(const std::vector<Vec3>& vertices, const Vec3& point);
std::vector<double> averageFaceDistance(const std::vector<double>& distances, const std::vector<Face>& faces);
std::vector<int> argsort_desc(const std::vector<double>& values);
std::vector<Triangle> getTriangles(const std::vector<Face>& faces, const cv::Mat& projectedPoints, const std::vector<int> sortedIndices);
double maxValue(const std::vector<double>& vec);
double minValue(const std::vector<double>& vec);
#endif