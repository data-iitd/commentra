
#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, sa, a, b, i;
    char str[100000];

    scanf("%d %d", &n, &m);
    // Read two integers n and m from input

    scanf("%s", str);
    // Read a string from input

    sa = 0;
    // Initialize sa to 0

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '-')
        {
            sa++;
            // Increment sa if str[i] is '-'
        }
    }
    // Count the number of '-' characters in the input

    sa = (n - sa) < sa ? (n - sa) : sa;
    // Set sa to the minimum of n - sa and sa, possibly normalizing sa

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        // Read two integers a and b in each iteration of the loop

        b -= a;
        // Subtract a from b

        if ((b % 2) && (b <= (sa << 1)))
        {
            // Check if b is odd and within certain bounds
            printf("1\n");
            // Print "1\n" if condition is met
        }
        else
        {
            printf("0\n");
            // Print "0\n" otherwise
        }
    }
    // Join and print the contents of ss

    return 0;
}

