#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Read input and split into two strings, a and b
    char a[100], b[100];
    scanf("%s %s", a, b);

    // Determine the maximum length of the two strings
    int x = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);

    // Pad the shorter string with zeros on the left
    char *p = a;
    while (strlen(p) < x)
    {
        p = "0" + p;
    }

    // Pad the shorter string with zeros on the right
    p = b;
    while (strlen(p) < x)
    {
        p = p + "0";
    }

    // Initialize an empty string to store the result
    char s[100] = "";

    // Initialize carry to 0
    int c = 0;

    // Loop through each digit from right to left
    for (int i = 0; i < x; i++)
    {
        // Add the corresponding digits from a and b along with the carry
        int d = (b[i] - '0') + (a[x - i - 1] - '0') + c;

        // If the sum is greater than 9, set carry to 1 and append the tens digit
        if (d > 9)
        {
            s[i] = (d % 10) + '0';
            c = 1;
        }
        else
        {
            // Otherwise, append the sum and set carry to 0
            s[i] = d + '0';
            c = 0;
        }
    }

    // If there's a carry left after the final addition, append '1'
    if (c == 1)
    {
        s[x] = '1';
    }

    // Reverse the result string and print it as an integer
    int y = strlen(s);
    for (int i = 0; i < y; i++)
    {
        printf("%c", s[y - i - 1]);
    }

    printf("\n");

    return 0;
}

