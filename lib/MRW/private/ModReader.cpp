#include "ModReader.h"
#include <fstream>
#include <iostream>
#include <filesystem>

void IModReader::readFile(std::string filePath)
{
    std::cout << "Hola mundo 2\n";
    std::ifstream file("../lib/MRW/resources/export_descr_buildings.txt");
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        
    } else {
        std::cerr << "Unable to open file!" << std::endl;
    }
}