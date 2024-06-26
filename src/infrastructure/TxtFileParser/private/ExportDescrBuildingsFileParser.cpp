#include "ExportDescrBuildingsFileParser.h"

#include <fstream>
#include <iostream>

void ExportDescrBuildingsFileParser::parseFile(std::string filePath)
{
    std::ifstream infile(filePath);
    std::string line;
    while (std::getline(infile, line))
    {
        std::cout << line << std::endl;
    }
    
}
