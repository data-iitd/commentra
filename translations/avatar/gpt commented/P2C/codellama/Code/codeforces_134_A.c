
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the list of integers
    int w[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    // Calculate the sum of the list
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += w[i];
    }

    // Initialize an empty list to store indices
    int d[n];
    int d_size = 0;

    // Iterate through each element in the list
    for (int i = 0; i < n; i++)
    {
        // Check if removing the current element results in an average equal to the current element
        if ((x - w[i]) / (n - 1) == w[i])
        {
            // If the condition is met, append the 1-based index to the list
            d[d_size++] = i + 1;
        }
    }

    // Print the number of valid indices found
    printf("%d\n", d_size);

    // Print the valid indices as a space-separated string
    for (int i = 0; i < d_size; i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}

