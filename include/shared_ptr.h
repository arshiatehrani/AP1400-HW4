#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>

template <typename T>
class SharedPtr {
public:
    // Constructors & Destructor
    SharedPtr(T*); // Constructor
    SharedPtr(const SharedPtr&); // Copy Constructor
    SharedPtr(); // Default Constructor
    ~SharedPtr(); // Destructor

    // Methods
    T* get() const;
    void reset();
    void reset(T*);
    template <typename A>
    friend A* make_shared(A);
    size_t use_count();

    // Operators
    SharedPtr& operator=(const SharedPtr<T>&);
    T operator*();
    T* operator->();
    operator bool();

private:
    T* _p;
    static inline size_t ptr_count {};
};

#include "shared_ptr.hpp"
#endif // SHARED_PTR