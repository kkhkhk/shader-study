#include <regex>
#include <iostream>
#include <string>

using namespace std;

regex pat1 (R"(\w{2}\s*\d{5}(-\d{4})?)"); // US postal code pattern: XXddddd-dddd and variants
regex pat2 {"\\w{2}\s*\\d{5}(-\\d{4})?"}; // U.S. postal code pattern

void use1()
{
    int lineno = 0;
    for (string line; getline(cin, line);)
    {
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pat1))
            cout << lineno << ":" << matches[0] << "\n";
    }
}