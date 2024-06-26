#ifndef HIDDENRESOURCESREPOSITORY
#define HIDDENRESOURCESREPOSITORY

#include "Buildings/HiddenResource.h"
#include "IRepository.h"

#include <vector>

class HiddenResourceRepository : public IRepository<HiddenResource*> {
    private:
        std::vector<HiddenResource*> hiddenResources;

    public:
        virtual std::vector<HiddenResource*> getAll() override;
        virtual bool save(HiddenResource* entity) override;

    public:
        HiddenResourceRepository() {};
};

#endif