#include "BuildingRepository.h"
#include "ModReader.h"
#include <iostream>

ModReader::ModReader(std::string fileDefinitionsDbPath) 
{
    this->definitionsLoader_ = new DefinitionsLoader(fileDefinitionsDbPath);
    BuildingRepository* buildingRepository = new BuildingRepository();
}

void ModReader::readFile()
{

}