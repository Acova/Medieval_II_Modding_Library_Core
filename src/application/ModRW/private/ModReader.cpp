#include "Buildings/IBuildingRepository.h"
#include "Buildings/IBuildingLevelRepository.h"
#include "Buildings/IHiddenResourceRepository.h"
#include "BuildingRepository.h"
#include "BuildingLevelRepository.h"
#include "HiddenResourceRepository.h"
#include "ModReader.h"

#include <iostream>

ModReader::ModReader(std::string fileDefinitionsDbPath) 
{
    this->definitionsLoader_ = new DefinitionsLoader(fileDefinitionsDbPath);
    IBuildingRepository* buildingRepository = new BuildingRepository();
    IHiddenResourceRepository* hiddenResourceRepository = new HiddenResourceRepository();
    IBuildingLevelRepository* buildingLevelRepository = new BuildingLevelRepository();
}

void ModReader::readFile()
{

}