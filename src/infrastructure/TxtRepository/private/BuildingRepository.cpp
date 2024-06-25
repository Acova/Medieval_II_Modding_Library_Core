#include "BuildingRepository.h"

std::vector<Building *> BuildingRepository::getAll()
{
    return this->buildings;
}

bool BuildingRepository::save(Building* entity)
{
    this->buildings.push_back(entity);
    return true;
}
