#include <vector>
#include "read_file.hpp"

struct Point3D {
    float x;
    float y;
    float z;
};

std::vector<Point3D> generateTerrain(const PGMImage& img, float Sh, float Hmin, float scaleXZ = 1.0f) {
};