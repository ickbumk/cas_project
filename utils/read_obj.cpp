#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "read_obj.hpp"


void read_file(const std::string& filename, std::vector<Vec3>& vertices, std::vector<Vec3>& vertex_normals, std::vector<Face>& faces) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open .obj file!\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v") {
            Vec3 v;
            iss >> v.x >> v.y >> v.z;
            vertices.push_back(v);

        } else if (type == "vn") {
            Vec3 vn;
            iss >> vn.x >> vn.y >> vn.z;
            vertex_normals.push_back(vn);

        } else if (type == "f") {
            Face f;
            std::string token;
            while (iss >> token) {
                std::replace(token.begin(), token.end(), '/', ' ');
                std::istringstream token_stream(token);
                int v_idx = 0, t_idx = 0, n_idx = 0;
                token_stream >> v_idx >> t_idx >> n_idx;

                f.ind_vertex.push_back(v_idx);
                f.ind_normal.push_back(n_idx);
            }
            faces.push_back(f);
        }
    }

    file.close();
}
