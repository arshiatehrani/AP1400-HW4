#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <iostream>

template <typename T>
class UniquePtr {
public:
    // Constructors & Destructor
    UniquePtr(T*); // Constructor
    UniquePtr(const UniquePtr&) = delete; // Copy Constructor
    UniquePtr(); // Default Constructor
    ~UniquePtr(); // Destructor

    // Methods
    T* get() const;
    T* release();
    void reset();
    void reset(T*);
    template <typename A>
    friend A* make_unique(A);

    // Operators
    UniquePtr& operator=(const UniquePtr<T>&) = delete;
    T operator*();
    T* operator->();
    operator bool();

private:
    T* _p;
};

#include "unique_ptr.hpp"
#endif // UNIQUE_PTR