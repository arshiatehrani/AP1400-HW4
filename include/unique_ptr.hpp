template <typename T>
UniquePtr<T>::UniquePtr(T* _N)
    : _p { _N }
{
}

template <typename T>
UniquePtr<T>::UniquePtr()
    : _p { nullptr }
{
}

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    delete _p;
    _p = nullptr;
}

template <typename T>
T* UniquePtr<T>::get() const
{
    return _p;
}

template <typename T>
T* UniquePtr<T>::release()
{
    T* ptr { new T { *_p } };
    delete _p;
    _p = nullptr;
    return ptr;
}

template <typename T>
void UniquePtr<T>::reset()
{
    delete _p;
    _p = nullptr;
}

template <typename T>
void UniquePtr<T>::reset(T* _N)
{
    delete _p;
    _p = _N;
}

template <typename A>
A* make_unique(A _N)
{
    A* ptr;
    ptr = new A { _N };
    return ptr;
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