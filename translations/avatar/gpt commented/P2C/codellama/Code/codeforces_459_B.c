#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, a, b, ac, bc;
    int *l1;

    // Read an integer input for the number of elements
    scanf("%d", &n);

    // Allocate memory for the list
    l1 = (int *)malloc(n * sizeof(int));

    // Read a line of input, split it into individual strings, convert them to integers, and store them in a list
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l1[i]);
    }

    // Sort the list of integers in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (l1[i] > l1[j])
            {
                int temp = l1[i];
                l1[i] = l1[j];
                l1[j] = temp;
            }
        }
    }

    // Assign the maximum value in the list to variable 'a'
    a = l1[n - 1];

    // Assign the minimum value in the list to variable 'b'
    b = l1[0];

    // Check if the maximum and minimum values are the same
    if (a == b)
    {
        // If they are the same, the difference is zero and the number of pairs is n choose 2
        printf("%d %d\n", a - b, (n) * (n - 1) / 2);
    }
    else
    {
        // Count occurrences of the maximum value 'a' in the list
        ac = 0;
        for (i = 0; i < n; i++)
        {
            if (l1[i] == a)
            {
                ac++;
            }
        }

        // Count occurrences of the minimum value 'b' in the list
        bc = 0;
        for (i = 0; i < n; i++)
        {
            if (l1[i] == b)
            {
                bc++;
            }
        }

        // Calculate the difference between the maximum and minimum values, and the product of their counts
        printf("%d %d\n", a - b, ac * bc);
    }

    // Free the memory allocated for the list
    free(l1);

    return 0;
}

