#include <cmath>
#include <vector>
#include <iostream>
#include "read_obj.hpp"  
#include <algorithm> // For std::max_element
#include <opencv4/opencv2/opencv.hpp>
#include <limits>

double minValue(const std::vector<double>& vec) {
    if (vec.empty()) return std::numeric_limits<double>::infinity(); // or throw an error
    return *std::min_element(vec.begin(), vec.end());
}

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

std::vector<double> calculateDistance(const std::vector<Vec3>& vertices, const Vec3& point) {
    std::vector<double> distances;
    for (const auto& v : vertices) {
        double distance = std::sqrt(std::pow(v.x - point.x, 2) + std::pow(v.y - point.y, 2) + std::pow(v.z - point.z, 2));
        distances.push_back(distance);
    }
    return distances;
}

std::vector<double> averageFaceDistance(const std::vector<double>& distances, const std::vector<Face>& faces) {
    std::vector<double> avgDistances(faces.size(), 0.0);
    
    for (size_t i = 0; i < faces.size(); ++i) {
        const auto& face = faces[i];
        int a=face.ind_vertex[0];
        int b=face.ind_vertex[1];
        int c=face.ind_vertex[2];
        double distanceA = distances[a];
        double distanceB = distances[b];
        double distanceC = distances[c];
        avgDistances[i] = (distanceA + distanceB + distanceC) / 3.0;

    }

    return avgDistances;
}

std::vector<int> argsort_desc(const std::vector<double>& values) {
    std::vector<int> indices(values.size());
    
    // Fill with 0, 1, ..., N-1
    for (size_t i = 0; i < indices.size(); ++i)
        indices[i] = static_cast<int>(i);

    // Sort indices based on values in descending order
    std::sort(indices.begin(), indices.end(),
              [&values](int a, int b) {
                  return values[a] > values[b]; // Descending
              });

    return indices;
}

std::vector<Triangle> getTriangles(const std::vector<Face>& faces, const cv::Mat& projectedPoints, const std::vector<int> sortedIndices) {
    std::vector<Triangle> triangles;
    for (const auto& index : sortedIndices) {
        const auto& face = faces[index];
        Triangle triangle;
        int indexA = face.ind_vertex[0];
        int indexB = face.ind_vertex[1];
        int indexC = face.ind_vertex[2];

        Vec2Int a, b, c;
        a.u = projectedPoints.at<int>(indexA, 0);
        a.v = projectedPoints.at<int>(indexA, 1);
        b.u = projectedPoints.at<int>(indexB, 0);
        b.v = projectedPoints.at<int>(indexB, 1);
        c.u = projectedPoints.at<int>(indexC, 0);
        c.v = projectedPoints.at<int>(indexC, 1);
        triangle.a.push_back(a);
        triangle.b.push_back(b);
        triangle.c.push_back(c);
        triangles.push_back(triangle);
    }
    return triangles;
}

double maxValue(const std::vector<double>& vec) {
    if (vec.empty()) return -std::numeric_limits<double>::infinity(); // or throw an error

    return *std::max_element(vec.begin(), vec.end());
}