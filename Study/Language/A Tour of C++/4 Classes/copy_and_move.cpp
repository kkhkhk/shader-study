#include <utility>

using namespace std;

class Vector
{
private:
    double *elem; // elem points to an array of sz doubles
    int sz;

public:
    Vector(int s);                  // constructor: establish invariant, acquire resources
    ~Vector() { delete[] elem; }    // destructor: release resources

    Vector(const Vector &a);            // copy constructor
    Vector &operator=(const Vector &a); // copy assignment

    Vector(Vector &&a);                 // move constructor
    Vector &operator=(Vector &&a);      // move assignment

    double &operator[](int i);
    const double &operator[](int i) const;

    int size() const;
};

Vector::Vector(const Vector &a) : elem{new double[a.sz]}, sz{a.sz} // copy constructor, allocate space for elements
{
    for (int i = 0; i != sz; ++i)   // copy elements
        elem[i] = a.elem[i];
}

Vector &Vector::operator=(const Vector &a) // copy assignment
{
    double *p = new double[a.sz];
    for (int i = 0; i != a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

Vector::Vector(Vector &&a) : elem{a.elem}, sz{a.sz} // 'grab the elements' from a
{
    a.elem = nullptr;                               // now a has no elements
    a.sz = 0;
}

Vector f()
{
    Vector x(1000);
    Vector y(1000);
    Vector z(1000);
    z = x;          // we get a copy
    y = move(x);    // we get a move
    return z;       // we get a move
}