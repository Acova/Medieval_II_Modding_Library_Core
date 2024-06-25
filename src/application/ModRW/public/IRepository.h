#ifndef IREPOSITORY
#define IREPOSITORY

#include <vector>

template<class T>
class IRepository {
    public:
        virtual std::vector<T> getAll();
        virtual bool save(T entity);
};

#endif