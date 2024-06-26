#include "BuildingLevelRepository.h"

std::vector<BuildingLevel *> BuildingLevelRepository::getAll()
{
    return this->buildingLevels;
}

bool BuildingLevelRepository::save(BuildingLevel *entity)
{
    this->buildingLevels.push_back(entity);
    return true;
}
