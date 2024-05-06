#include "FileDefinition.h"
#include "ModReader.h"
#include "DefinitionsLoader.h"
#include <iostream>

void ModReader::readFile(std::string filePath)
{
    std::cout << "Hola mundo 2\n";
    FileDefinition* prueba = new FileDefinition(1, "hola mundo 1", "hola mundo 2");
    std::vector<FileDefinition>* fileDefinitions = DefinitionsLoader::getFileDefinitions();
}