#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>


bool FileManager::writeToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Error opening the file!" << std::endl;
        return false;
    }
    file << data << std::endl;
    file.close();
    return true;
}

bool FileManager::readFromFile(const std::string& filename, std::string& data) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening the file!" << std::endl;
        return false;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    data = buffer.str();
    file.close();
    return true;
}
