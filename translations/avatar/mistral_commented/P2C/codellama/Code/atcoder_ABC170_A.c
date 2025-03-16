
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare a variable to store the number of integers
    int n;

    // Read the number of integers from the standard input
    scanf("%d", &n);

    // Declare an array to store the integers
    int a[n];

    // Read the integers from the standard input
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Iterate over the elements of the array a
    for (int i = 0; i < n; i++)
    {
        // Check if the current value is equal to zero
        if (a[i] == 0)
        {
            // Print the index of the first zero to the standard output
            printf("%d\n", i + 1);
            // Terminate the loop using the break statement
            break;
        }
    }

    return 0;
}

