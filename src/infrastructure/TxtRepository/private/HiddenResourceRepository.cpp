#include "HiddenResourceRepository.h"

std::vector<HiddenResource *> HiddenResourceRepository::getAll()
{
    return this->hiddenResources;
}

bool HiddenResourceRepository::save(HiddenResource *entity)
{
    this->hiddenResources.push_back(entity);
    return true;
}
