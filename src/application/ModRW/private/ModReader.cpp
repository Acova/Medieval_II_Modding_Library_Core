#include "BuildingRepository.h"
#include "BuildingLevelRepository.h"
#include "HiddenResourceRepository.h"
#include "ModReader.h"

#include <iostream>

ModReader::ModReader(std::string fileDefinitionsDbPath) 
{
    this->definitionsLoader_ = new DefinitionsLoader(fileDefinitionsDbPath);
    BuildingRepository* buildingRepository = new BuildingRepository();
    HiddenResourceRepository* hiddenResourceRepository = new HiddenResourceRepository();
    BuildingLevelRepository* buildingLevelRepository = new BuildingLevelRepository();
}

void ModReader::readFile()
{

}