#ifndef IBUILDINGREPOSITORY
#define IBUILDINGREPOSITORY

#include "Building.h"
#include <vector>

class IBuildingRepository {
    public:
        std::vector<Building> getAllBuildings();
};

#endif