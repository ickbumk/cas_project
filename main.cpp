#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "read_obj.hpp"
#include "visualize2d.hpp"
#include "mathUtils.hpp"
#include "cameraProperties.hpp"
#include <opencv4/opencv2/opencv.hpp>

int main(int argc, char* argv[]) {

    std::string filename = "../dataset/Weisshai_Great_White_Shark/meshes/model.obj";
    std::vector<Vec3> vertices;
    std::vector<Face> faces; 
    std::vector<Vec3> vertex_normals;
    read_file(filename, vertices, vertex_normals, faces); // Pass faces as a non-const reference

        
    std::cout << "Loaded " << vertices.size() << " vertices with "<< vertex_normals.size() << " normals and " << faces.size() << " faces." << std::endl;
    std::cout << "First face: " << faces[0].ind_vertex[0] << faces[0].ind_vertex[1]<< faces[0].ind_vertex[2] << std::endl;
    
    std::vector<Vec3> normalizedVertices = normalizeVertex(vertices);

    cv::Mat intrinsicMatrix = getSampleIntrinsicMatrix();
    std::cout << "Intrinsic Matrix: \n" << intrinsicMatrix << std::endl;

    cv::Vec3d eye(0, 0, 2);       // camera position
    cv::Vec3d target(-0.5, 0, 0);    // looking at origin
    cv::Vec3d up(0, 1, 0);        // y-up

    cv::Mat rtMatrix = getLookAtRT(eye, target, up);
    std::cout << "Camera RT Matrix: \n" << rtMatrix << std::endl;    

    Vec3 cameraPosition = getCameraPosition(rtMatrix);
    std::cout << "Camera Position: " << cameraPosition.x << ", " << cameraPosition.y << ", " << cameraPosition.z << std::endl;

    cv::Mat projectionMatrix = intrinsicMatrix * rtMatrix;
    std::cout << "Projection Matrix: \n" << projectionMatrix << std::endl;

    std::vector<double> distances = calculateDistance(normalizedVertices, cameraPosition);
    std::vector<double> facedistances = averageFaceDistance(distances, faces);
    std::vector<int> sortedIndices = argsort_desc(facedistances);


    // Project the vertices
    cv::Mat projectedPoints = projectPoints(normalizedVertices, projectionMatrix);
    // std::cout << "Projected Points: \n" << projectedPoints << std::endl;

    std::vector<Triangle> triangles = getTriangles(faces, projectedPoints, sortedIndices);
    // std::cout << "Triangles: " << triangles.size() << std::endl;
    // for (const auto& triangle : triangles) {
    //     std::cout << "Triangle: " << triangle.a[0].u << ", " << triangle.a[0].v << " | "
    //               << triangle.b[0].u << ", " << triangle.b[0].v << " | "
    //               << triangle.c[0].u << ", " << triangle.c[0].v << std::endl;
    // }


    //Get a 2D zero array(grayscale)
    cv::Mat image = cv::Mat::zeros(512, 512, CV_8UC1); // 2D array of zeros (black image)
    drawTriangle(image, triangles, facedistances, sortedIndices); // Draw the triangles on the image
    writeImage(image, "../BlackImage.png");


    
    return 0;
}