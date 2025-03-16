#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare a variable 'A' to store the input
    int *A;

    // Allocate memory for the input
    A = (int *)malloc(sizeof(int) * 4);

    // Read the input
    scanf("%d %d %d %d", &A[0], &A[1], &A[2], &A[3]);

    // Check if the second or third element of the list 'A' is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0])
    {
        // If the condition is true, print '0'
        printf("0\n");
    }
    else
    {
        // If the condition is false, sort the list 'A' in ascending order
        qsort(A, 4, sizeof(int), compare);

        // Print the difference between the third and second elements of the sorted list
        printf("%d\n", A[2] - A[1]);
    }

    // Free the memory allocated for the input
    free(A);

    return 0;
}

// Function to compare two integers
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

