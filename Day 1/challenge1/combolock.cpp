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
        cur_pos = (direction == 'R') ? (cur_pos + step) % 100
        : (cur_pos - step) % 100;
        if(cur_pos < 0) cur_pos += 100;
        if(cur_pos == 0) counter++;
    }

    infile.close();
    cout << "Total: " << counter << endl;
}