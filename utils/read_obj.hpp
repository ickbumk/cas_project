#ifndef READ_OBJ_H
#define READ_OBJ_H
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

struct Vec2Int{
    int u,v;
};


// face is consisted of three points with texture and normal
struct Face{
    std::vector<int> ind_vertex;
    std::vector<int> ind_texture;
    std::vector<int> ind_normal;
};

struct Triangle{
    std::vector<Vec2Int> a;
    std::vector<Vec2Int> b;
    std::vector<Vec2Int> c;
};

void read_file(const std::string & filename, std::vector<Vec3> & vertices, std::vector<Vec3> & vertex_normals, std::vector<Face> & faces);

#endif