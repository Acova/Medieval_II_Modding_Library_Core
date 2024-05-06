#include "FileDefinition.h"
#include "ModReader.h"
#include "DefinitionsLoader.h"
#include <iostream>

void ModReader::readFile(std::string filePath)
{
    std::cout << "Hola mundo 2\n";
    std::vector<FileDefinition>* fileDefinitions = DefinitionsLoader::getFileDefinitions();
}