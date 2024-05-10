#include "DefinitionsLoader.h"
#include <iostream>

DefinitionsLoader::DefinitionsLoader(char* fileDefinitionsDbPath)
{
    int result = sqlite3_open(fileDefinitionsDbPath, &this->database_);
}

std::vector<FileDefinition>* DefinitionsLoader::getFileDefinitions()
{
    std::cout << "Hola mundo 3" << std::endl;
    return new std::vector<FileDefinition>();
}