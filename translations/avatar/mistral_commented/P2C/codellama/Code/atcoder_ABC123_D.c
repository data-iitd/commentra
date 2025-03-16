#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, k, i, j, temp;
    int *a, *b, *c, *ab, *abc;

    // Read input: four integers x, y, z, and k followed by x * y integers each for lists a, b, and c
    scanf("%d %d %d %d", &x, &y, &z, &k);

    // Initialize an empty list ab to store the sum of each element from list a with each element from list b
    ab = (int *)malloc(x * y * sizeof(int));

    // Iterate through each element in list a for i, and for each element in list b for j, append their sum to list ab
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            ab[i * y + j] = a[i] + b[j];
        }
    }

    // Sort list ab in descending order
    for (i = 0; i < x * y - 1; i++)
    {
        for (j = i + 1; j < x * y; j++)
        {
            if (ab[i] < ab[j])
            {
                temp = ab[i];
                ab[i] = ab[j];
                ab[j] = temp;
            }
        }
    }

    // Initialize an empty list abc to store the sum of each element from list ab with each element from list c
    abc = (int *)malloc(k * z * sizeof(int));

    // Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to list abc
    for (i = 0; i < min(k, x * y); i++)
    {
        for (j = 0; j < z; j++)
        {
            abc[i * z + j] = ab[i] + c[j];
        }
    }

    // Sort list abc in descending order
    for (i = 0; i < k * z - 1; i++)
    {
        for (j = i + 1; j < k * z; j++)
        {
            if (abc[i] < abc[j])
            {
                temp = abc[i];
                abc[i] = abc[j];
                abc[j] = temp;
            }
        }
    }

    // Iterate through the first k elements of list abc and print each element
    for (i = 0; i < k; i++)
    {
        printf("%d\n", abc[i]);
    }

    // Free memory
    free(ab);
    free(abc);

    return 0;
}

