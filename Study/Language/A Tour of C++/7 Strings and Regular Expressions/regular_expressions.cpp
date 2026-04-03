#include <regex>

using namespace std;

regex pat1 (R"(\w{2}\s*\d{5}(-\d{4})?)"); // US postal code pattern: XXddddd-dddd and variants
regex pat2 {"\\w{2}\s*\\d{5}(-\\d{4})?"}; // U.S. postal code pattern