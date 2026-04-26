#pragma once 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct PGMImage {
    int width;
    int height;
    int maxVal;
    std::vector<unsigned char> data;
};

void skipComments(std::ifstream& file) {
};

PGMImage readPGMP5(const std::string& filename) {
};