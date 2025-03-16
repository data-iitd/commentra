#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Read an integer input n which represents the threshold for majority
    int n;
    scanf("%d", &n);

    // Read a line of input, split it into a list of strings, and store it in m
    char *m = malloc(1000000 * sizeof(char));
    scanf("%[^\n]%*c", m);

    // Initialize a variable to track if a majority element is possible
    int possible = 1;

    // Iterate through each unique element in the list m
    for (int i = 0; i < strlen(m); i++)
    {
        // Check if the count of the current element i is greater than or equal to n/2 + 1
        if (strchr(m, m[i]) - m >= n / 2 + 1)
        {
            // If it is, set possible to False and break the loop
            possible = 0;
            break;
        }
    }

    // Print 'YES' if a majority element is not found, otherwise print 'NO'
    printf("%s\n", possible ? "YES" : "NO");

    return 0;
}

