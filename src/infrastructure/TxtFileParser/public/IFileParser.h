#ifndef IFILEPARSER
#define IFILEPARSER

class IFileParser {
    public:
        virtual ~IFileParser() {};
        virtual void parseFile() const = 0;
};

#endif