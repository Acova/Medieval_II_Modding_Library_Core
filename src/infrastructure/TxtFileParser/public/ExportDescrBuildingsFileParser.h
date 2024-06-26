#ifndef BUILDINGSFILEPARSER
#define BUILDINGSFILEPARSER

#include "Buildings/IBuildingRepository.h"
#include "Buildings/IBuildingLevelRepository.h"
#include "Buildings/IHiddenResourceRepository.h"
#include "FileDefinition.h"
#include "IFileParser.h"

#include <string>

class ExportDescrBuildingsFileParser : public IFileParser {
    private:
        IBuildingRepository* buildingRepository;
        IBuildingLevelRepository* buildingLevelRepository;
        IHiddenResourceRepository* hiddenResourceRepository;
        FileDefinition* fileDefinition;

    public:
        virtual void parseFile(std::string filePath) override;

    public:
        ExportDescrBuildingsFileParser() {};
        ExportDescrBuildingsFileParser(
            IBuildingRepository* buildingRepository,
            IBuildingLevelRepository* buildingLevelRepository,
            IHiddenResourceRepository* hiddenResourcesRepository
        ) {
            this->buildingRepository = buildingRepository;
            this->buildingLevelRepository = buildingLevelRepository;
            this->hiddenResourceRepository = hiddenResourceRepository;
        };
};

#endif