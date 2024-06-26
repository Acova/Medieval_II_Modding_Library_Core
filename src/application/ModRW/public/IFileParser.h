#ifndef IFILEPARSER
#define IFILEPARSER

class IFileParser {
    public:
        virtual ~IFileParser() {};
        virtual void parseFile() = 0;
};

#endif