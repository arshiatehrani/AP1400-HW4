#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>
template <typename T>
class SharedPtr {
public:
    SharedPtr(T*); // Constructor
    SharedPtr(const SharedPtr&); // Copy Constructor
    SharedPtr(); // Default Constructor
    ~SharedPtr(); // Destructor
    T* get();
    template <typename A>
    friend A* make_shared(A);
    T operator*();

private:
    T* _p;
};

#include "shared_ptr.hpp"
#endif // SHARED_PTR