#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <iostream>
template <typename T>
class UniquePtr {
public:
    UniquePtr(T*); // Constructor
    UniquePtr(const UniquePtr&); // Copy Constructor
    UniquePtr(); // Default Constructor
    ~UniquePtr(); // Destructor
    T* get() const;
    T* release();
    void reset();
    void reset(T*);
    template <typename A>
    friend A* make_unique(A);
    UniquePtr& operator=(const UniquePtr<T>&);
    T operator*();
    T* operator->();
    operator bool();

private:
    T* _p;
};

// template <typename T>
// T* make_unique(T);

#include "unique_ptr.hpp"
#endif // UNIQUE_PTR