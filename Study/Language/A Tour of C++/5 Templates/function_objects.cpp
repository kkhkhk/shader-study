#include <string>
#include <list>
#include <vector>

#include "parameterized_types.cpp"

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

template<typename C, typename P>
int count(const C &c, P pred)
{
    int cnt = 0;
    for (const auto &x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}

void f(const Vector<int> &vec, const list<string> &lst, int x, const string &s)
{
    cout << "number of values less than " << x
         << ": " << count(vec, Less_than<int>{x})
         << "\n";
    cout << "number of values less than " << s
         << ": " << count(lst, Less_than<string>{s})
         << "\n";
}

void f_lambda(const Vector<int> &vec, const list<string> &lst, int x, const string &s)
{
    cout << "number of values less than " << x
         << ": " << count(vec, [&](int a)
                          { return a < x; })
         << "\n";
    cout << "number of values less than " << s
         << ": " << count(lst, [&](const string &a)
                          { return a < s; })
         << "\n";
}