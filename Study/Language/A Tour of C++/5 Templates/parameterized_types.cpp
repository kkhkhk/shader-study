#include <string>
#include <list>

using namespace std;

template<typename T>
class Vector
{
private:
    T *elem;
    int sz;

public:
    explicit Vector(int s);
    ~Vector() { delete[] elem; }

    // ... copy and move operations ... 

    T &operator[](int i);
    const T &operator[](int i) const;
    int size() const { return sz; }
};

template<typename T>
Vector<T>::Vector(int s)
{
    if (s < 0)
        throw Negative_size{};
    elem = new T[s];
    sz = s;
}

template<typename T>
const T &Vector<T>::operator[](int i) const
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}