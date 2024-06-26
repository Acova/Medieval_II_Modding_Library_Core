#ifndef BUILDINGLEVELREPOSITORY
#define BUILDINGLEVELREPOSITORY

#include "Buildings/BuildingLevel.h"
#include "IRepository.h"

#include <vector>

class BuildingLevelRepository : public IRepository<BuildingLevel*> {
    private:
        std::vector<BuildingLevel*> buildingLevels;

    public:
        virtual std::vector<BuildingLevel*> getAll() override;
        virtual bool save(BuildingLevel* entity) override;

    public:
        BuildingLevelRepository() {};
};

#endif