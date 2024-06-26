#ifndef HIDDENRESOURCESREPOSITORY
#define HIDDENRESOURCESREPOSITORY

#include "Buildings/HiddenResource.h"
#include "Buildings/IHiddenResourceRepository.h"

#include <vector>

class HiddenResourceRepository : public IHiddenResourceRepository {
    private:
        std::vector<HiddenResource*> hiddenResources;

    public:
        virtual std::vector<HiddenResource*> getAll() override;
        virtual bool save(HiddenResource* entity) override;

    public:
        HiddenResourceRepository() {};
};

#endif