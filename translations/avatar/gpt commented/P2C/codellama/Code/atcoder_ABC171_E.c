#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    int *a;
    int total;
    int i;

    // Read an integer input N (not used in further calculations)
    scanf("%d", &N);

    // Read a list of integers from input and convert them to a list of integers
    a = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    // Calculate the total using the XOR operation across all elements in the list 'a'
    total = 0;
    for (i = 0; i < N; i++)
    {
        total ^= a[i];
    }

    // For each element in the list 'a', compute the XOR with 'total' and print the results
    // The results are converted to strings and joined with a space for output
    for (i = 0; i < N; i++)
    {
        printf("%d ", a[i] ^ total);
    }

    // Free the memory allocated for the list 'a'
    free(a);

    // End of code
    return 0;
}
