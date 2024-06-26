#ifndef IREPOSITORY
#define IREPOSITORY

#include <vector>

template<class T>
class IRepository {
    public:
        virtual std::vector<T> getAll() = 0;
        virtual bool save(T entity) = 0;
};

#endif