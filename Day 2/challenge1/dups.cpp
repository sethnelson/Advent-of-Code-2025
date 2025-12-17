#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ifstream infile("products.txt");
    string str; // a temporary string
    size_t sum = 0;
    ull bottom, top; // the low and high numbers of the range
    size_t delim_index;

    while( getline(infile, str, ',') ) // strings are comma delimited
    {
        delim_index = str.find("-"); // find index of the breakpoint
        bottom = stoull(str.substr(0, delim_index));
        top = stoull(str.substr(delim_index + 1, str.length()));
        for(ull i = bottom; i <= top; i++) // test all number in range given
        {
            string s = to_string(i);
            if (s.length() % 2 == 0 // if evenly divisible
                && s.substr(0,s.length()/2) == s.substr(s.length()/2, s.length())) { // and both halves match
                    sum += i;
                }
        }
    }
    infile.close();
    cout << "Total " << sum << endl;
}