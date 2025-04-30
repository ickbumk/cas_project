#ifndef MATH_UTILS_H
#define MATH_UTILS_H
#include <cmath>
#include <iostream>
#include <vector>
#include "read_obj.hpp" 

// double maxVertexNorm(const std::vector<Vec3>& vertices);
// Vec3 avgVertex(const std::vector<Vec3>& vertices);
std::vector<Vec3> normalizeVertex(const std::vector<Vec3>& vertices);

#endif