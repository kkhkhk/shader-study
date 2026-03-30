#include <cstddef>

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