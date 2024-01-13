#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

class FileManager {
public:
    static bool writeToFile(const std::string& filename, const std::string& data);
    static bool readFromFile(const std::string& filename, std::string& data);
};

#endif
