#ifndef FileEntryDefinition_H
#define FileEntryDefinition_H

#include <algorithm>
#include <cctype>
#include <regex>
#include <string>

class FileEntryDefinition {
    public:
        int id;
        std::string name;
        std::regex regularExpression;
        int matchGroup;
        FileEntryDefinition() {};
        FileEntryDefinition(int fileEntryId, std::string fileEntryName, std::regex fileEntryRegex, int fileEntryMatchGroup) {
            id = fileEntryId;
            name = fileEntryName;
            regularExpression = fileEntryRegex;
            matchGroup = fileEntryMatchGroup;
        };
        std::string getEntryForLine(std::string line) {
            std::cmatch results;
            std::regex_match(line.c_str(), results, regularExpression);
            std::string entry = results[matchGroup].str();
            this->ltrim(entry);
            this->rtrim(entry);
            return entry;
        };
        inline void ltrim(std::string& s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
        };
        inline void rtrim(std::string& s) {
            s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), s.end());
        };
};

#endif