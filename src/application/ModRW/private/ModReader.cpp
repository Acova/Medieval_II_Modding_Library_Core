#include "ModReader.h"
#include <iostream>

ModReader::ModReader(std::string* fileDefinitionsDbPath) 
{
    this->definitionsLoader_ = new DefinitionsLoader(fileDefinitionsDbPath);
}

void ModReader::readFile()
{

}