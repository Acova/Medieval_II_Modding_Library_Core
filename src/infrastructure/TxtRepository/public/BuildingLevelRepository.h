#ifndef BUILDINGLEVELREPOSITORY
#define BUILDINGLEVELREPOSITORY

#include "Buildings/BuildingLevel.h"
#include "Buildings/IBuildingLevelRepository.h"

#include <vector>

class BuildingLevelRepository : public IBuildingLevelRepository {
    private:
        std::vector<BuildingLevel*> buildingLevels;

    public:
        virtual std::vector<BuildingLevel*> getAll() override;
        virtual bool save(BuildingLevel* entity) override;

    public:
        BuildingLevelRepository() {};
};

#endif