#include <iostream>
#include <string>

using namespace std;

void f1()
{
    int i;
    cin >> i;       // read an integer into i

    double d;
    cin >> d;       // read a double-precision floating-point number into d
}

void f2()
{
    int i;
    double d;
    cin >> i >> d;
}

void hello()
{
    cout << "Please enter your name\n";
    string str;
    cin >> str;
    cout << "Hello, " << str << "!\n";
}

void hello_line()
{
    cout << "Please enter your name\n";
    string str;
    getline(cin, str);
    cout << "Hello, " << str << "\n";
}