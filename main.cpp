#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "read_obj.hpp"
//#include "occlusion_culling.hpp"



int main(int argc, char* argv[]) {
    // if (argc < 2) {
    //     std::cerr << "Usage: " << argv[0] << " <filename.obj>" << std::endl;
    //     return 1;
    // }
    std::string filename = "../dataset/Weisshai_Great_White_Shark/meshes/model.obj";
    std::vector<Vec3> vertices;
    std::vector<Face> faces; // Ensure this is a non-const reference
    std::vector<Vec3> vertex_normals;
    

    read_file(filename, vertices, vertex_normals, faces); // Pass faces as a non-const reference
    // read_file(argv[1], vertices, faces);
    
    std::cout << "Loaded " << vertices.size() << " vertices with "<< vertex_normals.size() << " normals and " << faces.size() << " faces." << std::endl;
    
    return 0;
}