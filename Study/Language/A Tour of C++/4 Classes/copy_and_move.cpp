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