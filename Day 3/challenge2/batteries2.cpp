#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "usage: {filename}\n";
        return -1;
    }
    string s;
    string x;
    int i, rem, temp, index;
    unsigned long long sum = 0;
    temp = index = 0;
    string best_12 = "";

    ifstream infile(argv[1]);

    while( getline(infile, s) )
    {
        for(rem=12; rem > 0; rem--) // find largest 12 ordered digits
        {
            // subtracting rem avoids searching too deep in the string on early iterations
            for(i=index; i <= (s.length() - rem); i++)
            {
                if (stoi(s.substr(i, 1)) > temp) // save and store highest digit found
                {
                    temp = stoi(s.substr(i, 1));
                    index = i; // next search will begin at index beyond best digit found
                }
            }
            best_12 += s.substr(index, 1);
            temp = 0;
            index++;
        }
        sum += stoull(best_12);
        best_12 = ""; // reset values for next string
        temp = index = 0;
    }
    infile.close();
    cout << "Total " << sum << endl;
}