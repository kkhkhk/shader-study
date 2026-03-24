#include <string>

using namespace std;

template <typename T>
class Less_than
{
    const T val;    // value to compare against
public:
    Less_than(const T &v) : val(v) {}
    bool operator()(const T &x) const { return x < val; } // call operator
};

void fct(int n, const string &s)
{
    Less_than<int> lti{42};             // lti(i) will compare i to 42 using < (i < 42)
    Less_than<string> lts{"Backus"};    // lts(s) will compare s to 'Backus' using < (s < 'Backus')
    bool b1 = lti(n);
    bool b2 = lts(s);
}