#include <iostream>

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