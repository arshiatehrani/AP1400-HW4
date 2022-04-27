template <typename T>
UniquePtr<T>::UniquePtr(T* _N)
    : _p { _N }
{
    std::cout << "UniquePtr constructor " << std::endl;
}

template <typename T>
UniquePtr<T>::UniquePtr()
    : _p { nullptr }
{
    std::cout << "UniquePtr default constructor " << std::endl;
}

template <typename T>
UniquePtr<T>::UniquePtr(const UniquePtr<T>&)
{
    throw std::logic_error("Compile error!");
}

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    std::cout << "UniquePtr Destructor " << std::endl;
    delete _p;
    _p = nullptr;
}

template <typename T>
T* UniquePtr<T>::get()
{
    std::cout << "get method " << std::endl;
    return _p;
}

template <typename T>
T* UniquePtr<T>::release()
{
    std::cout << "release method " << std::endl;
    T* ptr { new T { *_p } };
    delete _p;
    _p = nullptr;
    return ptr;
}

template <typename T>
void UniquePtr<T>::reset()
{
    std::cout << "reset_1 method " << std::endl;
    delete _p;
    _p = nullptr;
}

template <typename T>
void UniquePtr<T>::reset(T* _N)
{
    std::cout << "reset_2 method " << std::endl;
    delete _p;
    _p = _N;
}

template <typename A>
A* make_unique(A _N)
{
    std::cout << "make_unique method " << std::endl;
    A* ptr;
    ptr = new A { _N };
    return ptr;
}

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(const UniquePtr<T>&)
{
    throw std::logic_error("Compile error!");
}

template <typename T>
T UniquePtr<T>::operator*()
{
    return *get();
}

template <typename T>
T* UniquePtr<T>::operator->()
{
    return get();
}

template <typename T>
UniquePtr<T>::operator bool()
{
    if (this->get() != nullptr)
        return true;
    else
        return false;
}