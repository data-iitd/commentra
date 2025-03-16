#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, mn, mx, temp;
    int *A;

    // Read the number of elements in the list
    scanf("%d", &N);

    // Allocate memory for the list of integers
    A = (int *)malloc(N * sizeof(int));

    // Read the list of integers from input and convert them to a list of integers
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    // Initialize minimum and maximum indices for the range of elements that are out of place
    mn = N + 1;
    mx = -1;

    // Iterate through the list to find the first and last indices where the element is not in its correct position
    for (i = 0; i < N; i++)
    {
        // Check if the current index + 1 does not match the value at that index
        if (i + 1 != A[i])
        {
            // Update the minimum index if the current index is less than the current minimum
            mn = min(mn, i);
            // Update the maximum index if the current index is greater than the current maximum
            mx = max(mx, i);
        }
    }

    // If no elements were out of place, output '0 0'
    if (mx == -1)
    {
        printf("0 0\n");
    }
    else
    {
        // Reverse the subarray from mn to mx and concatenate it with the rest of the list
        for (i = mn, j = mx; i < j; i++, j--)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

        // Check if the modified list is sorted
        if (sorted(A, N) == A)
        {
            // If sorted, print the 1-based indices of the range that was reversed
            printf("%d %d\n", mn + 1, mx + 1);
        }
        else
        {
            // If not sorted, output '0 0'
            printf("0 0\n");
        }
    }

    // Free the memory allocated for the list of integers
    free(A);

    return 0;
}

