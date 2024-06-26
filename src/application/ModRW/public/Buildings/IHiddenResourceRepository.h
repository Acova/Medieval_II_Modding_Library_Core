#ifndef IHIDDENRESOURCESREPOSITORY
#define IHIDDENRESOURCESREPOSITORY

#include "Buildings/HiddenResource.h"

#include <vector>

class IHiddenResourceRepository {
    public:
        virtual std::vector<HiddenResource*> getAll() = 0;
        virtual bool save(HiddenResource* building) = 0;
};

#endif