#ifndef IFILEPARSER
#define IFILEPARSER

#include <string>

class IFileParser {
    public:
        virtual ~IFileParser() {};
        virtual void parseFile(std::string filePath) = 0;
};

#endif