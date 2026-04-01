#include <string>
#include <iostream>

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

string incantation;

void respond(const string &answer)
{
    if (answer == incantation)
    {
        // perform magic
    }
    else if (answer == "yes")
    {
        // ...
    }
    // ...
}

void print(const string &s)
{
    printf("For people who like printf: %s\n", s.c_str());
    cout << "For people who like streams: " << s << '\n';
}

using wstring = basic_string<wchar_t>;