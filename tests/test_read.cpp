#include <catch2/catch_test_macros.hpp>
#include "read_obj.hpp"

TEST_CASE("Checking OBJ file reading") {
    std::string filename = "../../dataset/Weisshai_Great_White_Shark/meshes/model.obj";
    std::vector<Vec3> vertices;
    std::vector<Face> faces;
    std::vector<Vec3> vertex_normals;
    
    read_file(filename, vertices, vertex_normals, faces); 

    REQUIRE(vertices.size() == 2958);
}