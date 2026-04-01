#include <string>

using namespace std;

string compose(const string &name, const string &domain)
{
    return name + '@' + domain;
}