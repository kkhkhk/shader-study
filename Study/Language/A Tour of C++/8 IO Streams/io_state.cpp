#include <iostream>
#include <vector>

using namespace std;

vector<int> read_ints(istream &is)
{
    vector<int> res;
    int i;
    while (is >> i) 
        res.push_back(i);
    return res;
}

int main()
{
    while (cin) 
    {
        for (int i; cin >> i;)
        {
            // ... use the integer ...
        }

        if (cin.eof())
        {
            // all is well we reached the end-of-file ...
        }
        else if (cin.fail())    // a potentially recoverable error
        {
            cin.clear(); // reset the state to good()
            char ch;
            if (cin >> ch)  // look for nesting represented by { ... }
            {
                switch (ch) 
                {
                case '{':
                    // ... start nested structure ...
                    break;
                case '}':
                    // ... end nested structure ...
                    break;
                default:
                    cin.setstate(ios_base::failbit);    // add fail() to cin's state
                }
            }
        }
    }
}