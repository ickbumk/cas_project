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

class obj_loader{
    //contains vectors to store list of these
    public:
        std::vector<Vec3> vertices;
        std::vector<Vec2> texture_coords;
        std::vector<Vec3> normals;
        std::vector<Face> faces;

        bool load(const std::string& filename){
            std::ifstream file(filename);
            if (!file.is_open()){
                std::cerr << "Failed to open the .obj file: " << filename << std::endl;
                return false;
            }
            std::string line;

        }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    std::cout << "You entered: " << number << std::endl;
    return 0;
}
