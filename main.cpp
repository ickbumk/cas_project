#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "read_obj.hpp"
#include "visualize2d.hpp"
#include <opencv4/opencv2/opencv.hpp>
//#include "occlusion_culling.hpp"



int main(int argc, char* argv[]) {

    std::string filename = "../dataset/Weisshai_Great_White_Shark/meshes/model.obj";
    std::vector<Vec3> vertices;
    std::vector<Face> faces; 
    std::vector<Vec3> vertex_normals;
    read_file(filename, vertices, vertex_normals, faces); // Pass faces as a non-const reference
        
    std::cout << "Loaded " << vertices.size() << " vertices with "<< vertex_normals.size() << " normals and " << faces.size() << " faces." << std::endl;


    std::cout << "First face" << faces[0] << std::endl;

    //Get a 2D zero array(grayscale)
    cv::Mat image = cv::Mat::zeros(512, 512, CV_8UC1); // 2D array of zeros (black image)
    writeImage(image, "../BlackImage.png");


    
    return 0;
}