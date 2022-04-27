template <typename T>
SharedPtr<T>::SharedPtr(T* _N)
    : _p { _N }
{
    std::cout << "SharedPtr constructor " << std::endl;
}

template <typename T>
SharedPtr<T>::SharedPtr()
    : _p { nullptr }
{
    std::cout << "SharedPtr default constructor " << std::endl;
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& ptr)
    : _p { new T { *(ptr._p) } }
{
    std::cout << "SharedPtr copy constructor" << std::endl;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    std::cout << "SharedPtr Destructor " << std::endl;
    delete _p;
    _p = nullptr;
}

template <typename T>
T* SharedPtr<T>::get()
{
    std::cout << "get method " << std::endl;
    return _p;
}

template <typename A>
A* make_shared(A _N)
{
    std::cout << "make_shared method " << std::endl;
    A* ptr;
    ptr = new A { _N };
    return ptr;
}