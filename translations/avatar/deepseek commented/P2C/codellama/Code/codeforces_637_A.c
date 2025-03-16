#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Read the integer n and the list of strings s from standard input
    int n;
    scanf("%d", &n);
    char s[1000000];
    scanf("%s", s);

    // Create a Counter object w from the list s
    int w[1000000];
    int i, j;
    for (i = 0; i < n; i++)
    {
        w[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[i] == s[j])
            {
                w[i]++;
            }
        }
    }

    // Reverse the list s
    char s_rev[1000000];
    for (i = 0; i < n; i++)
    {
        s_rev[i] = s[n - i - 1];
    }

    // Initialize two variables c and a to -1 and 0 respectively
    int c = -1;
    int a = 0;

    // Iterate over the items in the Counter object w
    for (i = 0; i < n; i++)
    {
        // Check if the count of the item is equal to the maximum count in the Counter object
        if (w[i] == max(w))
        {
            // Check if the index of the item in the reversed list s is greater than the current value of c
            if (s_rev[i] > c)
            {
                // Update the value of a to the current item and update the value of c to the index of the current item in the reversed list s
                a = s[i];
                c = s_rev[i];
            }
        }
    }

    // Print the value of a
    printf("%c", a);

    return 0;
}

