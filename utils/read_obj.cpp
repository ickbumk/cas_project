#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


#include "read_obj.hpp"



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

            // std::cout << "found vector "<< v.x << v.y << v.z <<"\n" ;
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

