#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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


int main() {
    //the initial file path, you could change to the destination you desire
    std::ifstream file("dataset/Weisshai_Great_White_Shark/meshes/model.obj");    
    if (!file) {
        std::cerr << "Failed to open .obj file! \n" << std::endl;
        return 1;
    }

    std::vector<Vec3> vertices;
    std::vector<Vec2> textures;
    std::vector<Vec3> normals;
    std::vector<Face> faces;

    std::string line;

    while (std::getline(file, line)){
        std::istringstream iss(line); // parse the line
        std::string prefix; 
        iss >> prefix; // get the first word to tell whether it is the vertex, face ,etc

        if (prefix == "v"){
            Vec3 vertex;
            iss>> vertex.x >> vertex.y >> vertex.z;
            vertices.push_back(vertex); // add the vertex (1 vector) to vertices (list of vectors)

            std::cout << "found vector "<< vertex.x << vertex.y << vertex.z <<"\n" ;
        }

    }
    return 0;
}
