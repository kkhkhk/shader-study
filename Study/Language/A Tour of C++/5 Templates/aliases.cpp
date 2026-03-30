#include <cstddef>
#include <string>

using size_t = unsigned int;

template<typename T>
class Vector
{
public:
    using value_type = T;
    // ...
};

template <typename C>
using Element_type = typename C::value_type;    // the type of C's elements

template<typename Container>
void algo(Container &c)
{
    Vector<Element_type<Container>> vec;        // keep results here
    // ... 
}

template<typename Key, typename Value>
class Map
{
    // ...
};