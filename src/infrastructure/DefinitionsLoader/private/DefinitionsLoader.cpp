#include "DefinitionsLoader.h"
#include <iostream>

std::vector<FileDefinition>* DefinitionsLoader::getFileDefinitions()
{
    std::cout << "Hola mundo 3" << std::endl;
    return new std::vector<FileDefinition>();
}