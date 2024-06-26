#include "Buildings/IBuildingRepository.h"
#include "Buildings/IBuildingLevelRepository.h"
#include "Buildings/IHiddenResourceRepository.h"
#include "BuildingRepository.h"
#include "BuildingLevelRepository.h"
#include "HiddenResourceRepository.h"
#include "ExportDescrBuildingsFileParser.h"
#include "ModReader.h"

ModReader::ModReader(std::string fileDefinitionsDbPath) 
{
    this->definitionsLoader_ = new DefinitionsLoader(fileDefinitionsDbPath);
    IBuildingRepository* buildingRepository = new BuildingRepository();
    IHiddenResourceRepository* hiddenResourceRepository = new HiddenResourceRepository();
    IBuildingLevelRepository* buildingLevelRepository = new BuildingLevelRepository();
    this->fileParsers["export_descr_buildings"] = new ExportDescrBuildingsFileParser(
        buildingRepository, 
        buildingLevelRepository, 
        hiddenResourceRepository
    );
}

void ModReader::readFile()
{

}