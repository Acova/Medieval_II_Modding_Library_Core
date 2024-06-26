#ifndef IBUILDINGREPOSITORY
#define IBUILDINGREPOSITORY

#include "Buildings/Building.h"

#include <vector>

class IBuildingRepository {
    public:
        virtual std::vector<Building*> getAll() = 0;
        virtual bool save(Building* building) = 0;
};

#endif