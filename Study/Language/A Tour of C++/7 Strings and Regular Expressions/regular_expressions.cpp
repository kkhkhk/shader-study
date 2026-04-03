#include <regex>
#include <iostream>
#include <string>
#include <fstream>

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

void use2()
{
    ifstream in("file.txt");
    if (!in)
        cerr << "no file\n";

    regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"};    // U.S. postal code pattern

    int lineno = 0;
    for (string line; getline(in, line);)
    {
        ++lineno;
        smatch matches;     // matched strings go here
        if (regex_search(line, matches, pat))
        {
            cout << lineno << ": " << matches[0] << "\n";   // the complete match
            if (1 < matches.size() && matches[1].matched)
                cout << "\t" << matches[1] << "\n";
        }
    }
}

bool is_identifier(const string &s)
{
    regex pat {R"([_[:alpha:]]\w*)"};
    return regex_match(s, pat);
}