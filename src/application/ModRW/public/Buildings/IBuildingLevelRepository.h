#ifndef IBUILDINGLEVELREPOSITORY
#define IBUILDINGLEVELREPOSITORY

#include "Buildings/BuildingLevel.h"

#include <vector>

class IBuildingLevelRepository {
        public:
        virtual std::vector<BuildingLevel*> getAll() = 0;
        virtual bool save(BuildingLevel* building) = 0;
};

#endif