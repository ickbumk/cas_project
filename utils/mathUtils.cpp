#include <cmath>
#include <vector>
#include <iostream>
#include "read_obj.hpp"  

double maxVertexNorm(const std::vector<Vec3>& vertices) {
    double maxNorm = 0.0;
    for (const auto& v : vertices) {
        double norm = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        if (norm > maxNorm) {
            maxNorm = norm;
        }
    }
    return maxNorm;
}

Vec3 avgVertex(const std::vector<Vec3>& vertices) {
    double xsum = 0.0, ysum = 0.0, zsum = 0.0;
    for (const auto& v : vertices) {
        xsum += v.x;
        ysum += v.y;
        zsum += v.z;
    }

    Vec3 avg;
    avg.x = xsum / vertices.size();
    avg.y = ysum / vertices.size();
    avg.z = zsum / vertices.size();
    return avg;
}

std::vector<Vec3> normalizeVertex(const std::vector<Vec3>& vertices) {
    Vec3 centroid = avgVertex(vertices);

    std::cout << "Centroid for this model is: " << centroid.x << ", " << centroid.y << ", " << centroid.z << std::endl;

    std::vector<Vec3> shiftedVertices;
    for (const auto& v : vertices) {
        Vec3 shifted;
        shifted.x = (v.x - centroid.x);
        shifted.y = (v.y - centroid.y);
        shifted.z = (v.z - centroid.z);
        shiftedVertices.push_back(shifted);
    }

    double maxShiftedNorm = maxVertexNorm(shiftedVertices);

    std::cout << "Max vertex norm: " << maxShiftedNorm << std::endl;

    std::vector<Vec3> normalizedVertices;
    for (const auto& v : shiftedVertices) {
        Vec3 normalized;
        normalized.x = v.x / maxShiftedNorm;
        normalized.y = v.y / maxShiftedNorm;
        normalized.z = v.z / maxShiftedNorm;
        normalizedVertices.push_back(normalized);
    }

    return normalizedVertices;
}
