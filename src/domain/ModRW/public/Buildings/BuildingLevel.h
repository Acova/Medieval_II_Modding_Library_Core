#ifndef BUILDINGLEVEL
#define BUILDINGLEVEL

#include <string>
#include <vector>

class BuildingLevel {
    public:
        std::string settlementType;
        std::string requirements;
        int converTo;
        std::vector<std::string> capabilities;;
        std::vector<std::string> factionCapabilities;
        std::string material;
        int contructionTime;
        int cost;
        std::string settlementMin;
        std::vector<BuildingLevel> upgrades;
};

#endif