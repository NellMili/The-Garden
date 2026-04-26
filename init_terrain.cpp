#include "init_terrain.hpp"

std::vector<Point3D> generateTerrain(const PGMImage& img, float Sh, float Hmin, float scaleXZ = 1.0f) {
    std::vector<Point3D> terrain;
    terrain.reserve(img.width * img.height); 

    // Parcours de la grille (j = Z/profondeur, i = X/largeur)
    for (int j = 0; j < img.height; ++j) {
        for (int i = 0; i < img.width; ++i) {
            
            // 1. Récupérer P(i,j) depuis le tableau 1D
            // Attention : les PGM stockent les valeurs en unsigned char
            unsigned char pixelValue = img.data[j * img.width + i];
            float P = static_cast<float>(pixelValue);

            // 2. Calculer l'élévation Y avec ta formule
            float y = (P * Sh) - Hmin;

            // 3. Calculer X et Z (avec un facteur d'espacement)
            // On peut aussi centrer le terrain en soustrayant (width/2) à i
            float x = static_cast<float>(i) * scaleXZ;
            float z = static_cast<float>(j) * scaleXZ;

            // 4. Ajouter le point à notre liste
            terrain.push_back({x, y, z});
        }
    }

    return terrain;
}