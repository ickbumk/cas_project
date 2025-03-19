#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


#include "occlusion_culling.hpp"

// defines a 3D vector, stores vertices and normals
struct Vec3{
    float x,y,z;
};

// defines 2d vector, stores texture coordinates
struct Vec2{
    float u,v;
};

// face is consisted of three points with texture and normal
struct Face{
    std::vector<int> ind_vertex;
    std::vector<int> ind_texture;
    std::vector<int> ind_normal;
};

void read_file(const std::string & filename, std::vector<Vec3> & vertices, std::vector<Vec3> & vertex_normals, std::vector<Face> & faces){
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open .obj file! \n" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)){
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v"){
            Vec3 v;
            iss>> v.x >> v.y >> v.z;
            vertices.push_back(v); // add the vertex (1 vector) to vertices (list of vectors)

            std::cout << "found vector "<< v.x << v.y << v.z <<"\n" ;
        } else if (type == "f"){
            Face f;
            int index;
            while (iss >> index){
                f.ind_vertex.push_back(index);
            }
            faces.push_back(f);
        } else if (type == "vn"){
            Vec3 vn;
            iss>> vn.x >> vn.y >> vn.z;
            vertex_normals.push_back(vn);

        }

    }
    file.close();

}

int main(int argc, char* argv[]) {
    // if (argc < 2) {
    //     std::cerr << "Usage: " << argv[0] << " <filename.obj>" << std::endl;
    //     return 1;
    // }
    std::string filename = "dataset/Weisshai_Great_White_Shark/meshes/model.obj";
    std::vector<Vec3> vertices;
    std::vector<Face> faces;
    std::vector<Vec3> vertex_normals;
    

    read_file(filename, vertices, vertex_normals, faces);
    // read_file(argv[1], vertices, faces);
    
    std::cout << "Loaded " << vertices.size() << " vertices with "<< vertex_normals.size() << " normals and " << faces.size() << " faces." << std::endl;
    
    return 0;
}