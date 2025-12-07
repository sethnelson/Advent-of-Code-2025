#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cur_pos = 50;
    int counter = 0;
    FILE* infile = fopen("combo.txt", "r");
    if (infile == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }
    char s[6]; //longest string in file is 4 chars
    char direction;
    int distance;

    while (fscanf(infile, "%5s", s) == 1) // While there are strings to be read
    {
        direction = s[0]; // the first char is the direction
        distance = atoi(&s[1]); // remainder of string is dial distance

        if (distance >= 100)
        {
            counter += distance / 100; // count each full rotation
            distance = distance % 100; // continue with remainder
        }

        if (direction == 'R')
        {
            if (cur_pos + distance >= 100) counter++;  // passed 100 going right, add click
            cur_pos = (cur_pos + distance) % 100;
        } else {
            if (cur_pos != 0 && cur_pos - distance <= 0) counter++; // passed 0 going left, add click
            cur_pos = (cur_pos - distance) % 100;
            if (cur_pos < 0) cur_pos += 100; // if our result is negative, add back 100 to get the positive expression on the combo wheel
        }
    }
    fclose(infile);
    printf("Total: %d\n", counter);
    return 0;
}