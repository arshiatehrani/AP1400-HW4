template <typename T>
SharedPtr<T>::SharedPtr(T* _N)
    : _p { _N }
{
    std::cout << "SharedPtr constructor " << std::endl;
    ptr_count++;
}

template <typename T>
SharedPtr<T>::SharedPtr()
    : _p { nullptr }
{
    std::cout << "SharedPtr default constructor " << std::endl;
    ptr_count++;
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& ptr)
    : _p { ptr._p }
{
    std::cout << "SharedPtr copy constructor" << std::endl;
    ptr_count++;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    std::cout << "SharedPtr Destructor " << std::endl;
    _p = nullptr;
    delete _p;
    ptr_count--;
}

template <typename T>
T* SharedPtr<T>::get() const
{
    std::cout << "get method " << std::endl;
    return _p;
}

template <typename T>
void SharedPtr<T>::reset()
{
    std::cout << "reset_1 method " << std::endl;
    delete _p;
    _p = nullptr;
}

template <typename T>
void SharedPtr<T>::reset(T* _N)
{
    std::cout << "reset_2 method " << std::endl;
    delete _p;
    _p = _N;
    ptr_count++;
}

template <typename A>
A* make_shared(A _N)
{
    std::cout << "make_shared method " << std::endl;
    A* ptr;
    ptr = new A { _N };
    return ptr;
}

template <typename T>
size_t SharedPtr<T>::use_count()
{
    std::cout << "use_count method " << std::endl;
    return ptr_count;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& ptr)
{
    if (_p == ptr.get())
        return *this;
    _p = ptr.get();
    return *this;
}

template <typename T>
T SharedPtr<T>::operator*()
{
    return *get();
}

template <typename T>
T* SharedPtr<T>::operator->()
{
    return get();
}

template <typename T>
SharedPtr<T>::operator bool()
{
    if (this->get() != nullptr)
        return true;
    else
        return false;
}