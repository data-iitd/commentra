
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize the variable 'n' to read the number of elements in the array 'a'
    int n;
    scanf("%d", &n);

    // Create a dynamic array 'a' of length 'n' to store the input elements
    int *a = (int *)malloc(n * sizeof(int));

    // Read 'n' elements from the standard input and store them in array 'a'
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Initialize an empty array 'b' of length 'n' to store the unique elements
    int *b = (int *)malloc(n * sizeof(int));

    // Initialize the length of array 'b' to 0
    int len_b = 0;

    // Iterate through each element 'v' in array 'a'
    for (int i = 0; i < n; i++)
    {
        // Use 'bsearch' function to find the index 'x' where 'v' should be inserted in array 'b'
        int x = bsearch(a[i], b, len_b);

        // If 'x' is equal to the length of array 'b', it means 'v' is not present in the array, so append it
        if (x == len_b)
        {
            b[len_b++] = a[i];
        }
        else
        {
            // Otherwise, replace the element at index 'x' in array 'b' with 'v'
            b[x] = a[i];
        }
    }

    // Print the length of array 'b' as the output
    printf("%d\n", len_b);

    // Free the memory allocated to arrays 'a' and 'b'
    free(a);
    free(b);

    // End of the code
    return 0;
}

int bsearch(int v, int *b, int len_b)
{
    // Initialize the left and right indices of the search range
    int left = 0, right = len_b - 1;

    // Iterate while the left index is less than or equal to the right index
    while (left <= right)
    {
        // Calculate the middle index of the search range
        int mid = (left + right) / 2;

        // If the element at index 'mid' is greater than 'v', set the right index to 'mid - 1'
        if (b[mid] > v)
        {
            right = mid - 1;
        }
        // Otherwise, set the left index to 'mid + 1'
        else
        {
            left = mid + 1;
        }
    }

    // Return the left index as the index where 'v' should be inserted
    return left;
}

