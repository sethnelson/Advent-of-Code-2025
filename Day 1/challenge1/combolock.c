#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cur_pos = 50;
    int counter = 0;
    FILE* fptr = fopen("combo.txt", "r");
    if (fptr == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }
    char s[5]; //longest string in file is 4 chars
    char direction;
    int distance;

    while (fscanf(fptr, "%4s", s) == 1) // While there are strings to be read
    {
        direction = s[0]; // the first char is the direction
        distance = atoi(&s[1]); // remainder of string is dial distance
        // if 'R' then advance position modulo 100, otherwise decrement position
        cur_pos = (direction == 'R') ? (cur_pos + distance) % 100 : (cur_pos - distance) % 100;
        if (cur_pos < 0) cur_pos += 100; // if our result is negative, add back 100 to get the positive expression on the combo wheel
        if (cur_pos == 0) counter++;
    }
    fclose(fptr);
    printf("Total: %d\n", counter);
    return 0;
}