#include <string>

using namespace std;

string compose(const string &name, const string &domain)
{
    return name + '@' + domain;
}

auto addr = compose("dmr", "Bell-labs.com");

void m2(string &s1, string &s2)
{
    s1 = s1 + '\n';
    s2 += '\n';
}