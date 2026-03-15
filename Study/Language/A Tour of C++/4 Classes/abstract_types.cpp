#include <iostream>
#include <initializer_list>
#include "concrete_types.cpp"
#include <list>
#include <stdexcept>

using namespace std;

class Container
{
public:
    virtual double &operator[](int) = 0; // pure virtual function
    virtual int size() const = 0;        // const member function
    virtual ~Container() {}              // destructor
};

void use(Container& c)
{
    const int sz = c.size();

    for (int i = 0; i != sz; i++)
        cout << c[i] << '\n';
}

class Vector_container : public Container
{
private:
    Vector v;

public:
    Vector_container(int s) : v(s) {}
    Vector_container(initializer_list<double> lst) : v(lst) {}
    ~Vector_container() {}

    double &operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

void g()
{
    Vector_container vc{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    use(vc);
}

class List_container : public Container // List_container implements Container
{
private:
    list<double> ld;                    // (standard-library) list of doubles

public:
    List_container() {}                 // empty List
    List_container(initializer_list<double> il) : ld{il} {}
    ~List_container() {}

    double &operator[](int i);
    int size() const { return ld.size(); }
};

double &List_container::operator[](int i)
{
    for (auto& x : ld)
    {
        if (i == 0)
            return x;
        --i;
    }
    throw out_of_range("List container");
}

void h()
{
    List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    use(lc);
}