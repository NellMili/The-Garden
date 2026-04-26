#include "read_file.hpp"

void skipComments(std::ifstream& file) {
    char ch;
    while (file >> std::ws && file.peek() == '#') {
        std::string str;
        std::getline(file, str);
    }
}

PGMImage readPGMP5(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Impossible d'ouvrir le fichier.");
    }
    std::string checkIfP5;
    file >> checkIfP5;
    if (checkIfP5 != "P5") {
        throw std::runtime_error("Ce n'est pas un format PGM P5 valide.");
    }
    PGMImage img;
    skipComments(file);
    file >> img.width; 
    skipComments(file);
    file >> img.height;
    skipComments(file);
    file >> img.maxVal;
    file.ignore();
    img.data.resize(img.width * img.height);
    file.read(reinterpret_cast<char*>(img.data.data()), img.data.size());

    return img;
}