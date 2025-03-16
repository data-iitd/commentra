#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, k;
    int *a, *b, *c;
    int *ab, *abc;
    int i, j, kk;

    // Read integers x, y, z, and k from input
    scanf("%d %d %d %d", &x, &y, &z, &k);

    // Allocate memory for lists a, b, and c
    a = (int *)malloc(x * sizeof(int));
    b = (int *)malloc(y * sizeof(int));
    c = (int *)malloc(z * sizeof(int));

    // Read list a of size x from input
    for (i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }

    // Read list b of size y from input
    for (i = 0; i < y; i++)
    {
        scanf("%d", &b[i]);
    }

    // Read list c of size z from input
    for (i = 0; i < z; i++)
    {
        scanf("%d", &c[i]);
    }

    // Allocate memory for the list of sums of elements from lists a and b
    ab = (int *)malloc((x * y) * sizeof(int));

    // Calculate all possible sums of elements from list a and list b
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            ab[i * y + j] = a[i] + b[j];
        }
    }

    // Sort the list of sums in descending order
    qsort(ab, x * y, sizeof(int), compare);

    // Allocate memory for the list of sums of the top k elements from ab and elements from list c
    abc = (int *)malloc((k * z) * sizeof(int));

    // Calculate sums of the top k elements from ab with each element in c
    for (kk = 0; kk < k; kk++)
    {
        for (i = 0; i < z; i++)
        {
            abc[kk * z + i] = ab[kk] + c[i];
        }
    }

    // Sort the resulting sums in descending order
    qsort(abc, k * z, sizeof(int), compare);

    // Print the top k sums from the final list abc
    for (i = 0; i < k; i++)
    {
        printf("%d\n", abc[i]);
    }

    // Free memory
    free(a);
    free(b);
    free(c);
    free(ab);
    free(abc);

    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

