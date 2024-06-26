#include "Buildings/IBuildingRepository.h"
#include "Buildings/IBuildingLevelRepository.h"
#include "Buildings/IHiddenResourceRepository.h"
#include "BuildingRepository.h"
#include "BuildingLevelRepository.h"
#include "ExportDescrBuildingsFileParser.h"
#include "HiddenResourceRepository.h"
#include "ModReader.h"

#include <iostream>

ModReader::ModReader(std::string fileDefinitionsDbPath, std::string modFolderPath) 
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
    for(auto const& [id, fileDefinition] : this->definitionsLoader_->getFileDefinitions()) {
        IFileParser* fileParser = this->fileParsers[fileDefinition->name];
        fileParser->parseFile(modFolderPath + fileDefinition->filePath);
    }
}

void ModReader::readFile()
{

}