#include <stdio.h>
#include <string.h>

int main()
{
    // Define the number of strings n and the number of operations m
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the number of '-' symbols in the input string
    int sa = 0;
    char str[100000];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '-')
        {
            sa++;
        }
    }

    // Ensure the number of '-' symbols is valid
    sa = min(n - sa, sa);

    // Initialize an empty list 'ss' to store the results of each operation
    char ss[100000];

    // Perform each operation as described in the problem statement
    for (int i = 0; i < m; i++)
    {
        // Read two integers a and b from the input
        int a, b;
        scanf("%d %d", &a, &b);

        // Calculate the difference between b and a
        b -= a;

        // Check if the difference is valid based on the number of '-' symbols
        if ((b % 2 == 0) || (b > sa << 1))
        {
            // If the difference is valid, add '1' to the result list 'ss'
            strcat(ss, "1\n");
        }
        // If the difference is not valid, add '0' to the result list 'ss'
        else
        {
            strcat(ss, "0\n");
        }
    }

    // Print the final result by joining all the strings in the 'ss' list with an empty string as separator
    printf("%s", ss);

    return 0;
}

