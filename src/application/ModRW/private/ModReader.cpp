#include "ModReader.h"
#include <iostream>

ModReader::ModReader(char* fileDefinitionsDbPath) 
{
    this->definitionsLoader_ = new DefinitionsLoader(fileDefinitionsDbPath);
}

void ModReader::readFile()
{
    std::cout << "Hola mundo 2\n";
}