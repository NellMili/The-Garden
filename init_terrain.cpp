#include "init_terrain.hpp"

std::vector<Point3D> generateTerrain(const PGMImage& img, float Sh, float Hmin, float scaleXZ = 1.0f) {
    std::vector<Point3D> terrain;
    terrain.reserve(img.width * img.height); 

    for (int j = 0; j < img.height; ++j) {
        for (int i = 0; i < img.width; ++i) {
            unsigned char pixelValue = img.data[j * img.width + i];
            float P = static_cast<float>(pixelValue);
            float y = (P * Sh) - Hmin;
            float x = static_cast<float>(i) * scaleXZ;
            float z = static_cast<float>(j) * scaleXZ;
            terrain.push_back({x, y, z});
        }
    }

    return terrain;
}
