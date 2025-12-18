#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2){
        cout << "usage: {filename} \n";
        return -1;
    }
    string s;
    string x, y;
    int i, first, second, f_index, sum;
    first = second = sum = 0;

    ifstream infile(argv[1]);

    while( getline(infile, s) )
    {
        for(i=0; i<s.length() - 1; i++) // search string exluding last char for largest number
        {
            if (stoi(s.substr(i, 1)) > first)
            {
                first = stoi(s.substr(i, 1));
                x = s[i];
                f_index = i; // store index of largest number found
            }
        }

        for(i = f_index + 1; i < s.length(); i++) // search string starting at index of first largest number
        {
            if (stoi(s.substr(i, 1)) > second)
            {
                second = stoi(s.substr(i, 1));
                y = s[i];
            }
        }
        string num = x + y; // concatenate first and second largest numbers
        sum += stoi(num);
        first = second = 0; // reset values for next string
    }
    infile.close();
    cout << "Total " << sum << endl;
}