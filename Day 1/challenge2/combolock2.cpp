#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int cur_pos = 50;
    int counter = 0;
    string str;
    char direction;
    int step;

    ifstream infile("combo.txt");

    while( getline(infile, str) )
    {
        direction = str[0];
        step = stoi(&str[1]);
        counter += step / 100;
        step %= 100;
        if (direction == 'R')
        {
            if (cur_pos + step >= 100) counter++;
            cur_pos = (cur_pos + step) % 100;
        } else {
            if (cur_pos - step <= 0 && cur_pos != 0) counter++;
            cur_pos = (cur_pos - step) % 100;
            if(cur_pos < 0) cur_pos += 100;
        }
    }

    cout << "Total " << counter << endl;
    infile.close();
    ofstream writefile("result.txt");
    writefile << counter;
    writefile.close();
}