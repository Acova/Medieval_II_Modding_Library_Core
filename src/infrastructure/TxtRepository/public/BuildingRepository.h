#ifndef BUILDINGREPOSITORY
#define BUILDINGREPOSITORY

#include "Buildings/Building.h"
#include "IRepository.h"

#include <vector>

class BuildingRepository : public IRepository<Building*> {
    public:
        std::vector<Building*> buildings;

    public:
        virtual std::vector<Building*> getAll() override;
        virtual bool save(Building* entity) override;

    public:
        BuildingRepository() {};
};

#endif