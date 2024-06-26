#ifndef BUILDINGREPOSITORY
#define BUILDINGREPOSITORY

#include "Buildings/Building.h"
#include "Buildings/IBuildingRepository.h"

#include <vector>

class BuildingRepository : public IBuildingRepository {
    private:
        std::vector<Building*> buildings;

    public:
        virtual std::vector<Building*> getAll() override;
        virtual bool save(Building* entity) override;

    public:
        BuildingRepository() {};
};

#endif