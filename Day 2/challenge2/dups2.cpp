#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef unsigned long long ull;
bool has_dups(string, int);

int main()
{
    ifstream infile("products.txt");
    string str; // a temporary string
    size_t sum = 0;
    ull bottom, top; // the low and high numbers of the range
    size_t delim_index;

    while( getline(infile, str, ',') ) // strings are comma delimited
    {
        delim_index = str.find("-");
        bottom = stoull(str.substr(0, delim_index));
        top = stoull(str.substr(delim_index + 1, str.length()));

        for(ull i = bottom; i <= top; i++) // test all numbers in range given
        {
            string s = to_string(i);
            bool is_dup;

            for(int j = 0; j < s.length()/2; j++)
            {
                string sub = s.substr(0, j + 1);
                if (s.length() % (j + 1) == 0) // only test if divisible by number of characters in string
                {
                    is_dup = true;
                    for(int k = 1; k < s.length() / (j + 1); k++) // evaluate each chunk, starting at index past chunk
                    {
                        if(sub != s.substr(k * sub.length(), sub.length())) // pattern mismatch
                        {
                            is_dup = false;
                            break; // stop analyzing this size of chunk
                        }
                    }
                }
                if (is_dup) break; // look no further, a full matching pattern has been found
            }
            if (is_dup) sum += i;
        }
    }
    infile.close();
    cout << "Total " << sum << endl;
}