#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100], i, e;
    char str[100];

    // Read a line of input
    scanf("%s", str);

    // Split the input into components
    int j = 0;
    char *p = strtok(str, " ");
    while (p != NULL)
    {
        // Convert each component to an integer
        a[j] = atoi(p);
        j++;
        p = strtok(NULL, " ");
    }

    // Iterate over the list 'a' using enumerate to get both the index (e) and the value (i)
    for (e = 0; e < j; e++)
    {
        // Check if the current value is zero
        if (a[e] == 0)
        {
            // Print the index (1-based) of the first occurrence of zero
            printf("%d\n", e + 1);
            // Exit the loop after finding the first zero
            break;
        }
    }

    return 0;
}

