#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

// Define the main function
int main()
{
    // Read input: number of test cases, number of lists, and the lists themselves
    int n, m;
    scanf("%d %d", &n, &m);
    int **li = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        li[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &li[i][j]);
        }
    }

    // Read input: pattern
    int p[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Create a set of all elements in the lists
    int *q = malloc(n * sizeof(int));
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q[k++] = li[i][j];
        }
    }
    q = realloc(q, k * sizeof(int));
    qsort(q, k, sizeof(int), NULL);
    int *r = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        r[i] = i + 1;
    }
    int *v = malloc(n * sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (bsearch(&q[i], r, k, sizeof(int), NULL) == NULL)
        {
            v[k++] = q[i];
        }
    }
    v = realloc(v, k * sizeof(int));

    // Initialize answer to 0
    int ans = 0;

    // Iterate through all possible subsets of q, from empty to the full set
    for (int i = 0; i <= k; i++)
    {
        // Iterate through all combinations of i elements from q
        for (int j = 0; j < pow(2, i); j++)
        {
            // Iterate through each list and pattern
            for (int l = 0; l < m; l++)
            {
                for (int k = 0; k < n; k++)
                {
                    // Check if the current combination of lists and pattern match the current subset of q
                    if (p[k]!= (j / pow(2, k)) % 2)
                    {
                        // If not, break out of the inner loop and move on to the next combination
                        break;
                    }
                }
            }
            // If all combinations of lists and pattern match the current subset of q, increment the answer
            if (k == n)
            {
                ans++;
            }
        }
    }

    // Print the answer
    printf("%d\n", ans);

    // Free memory
    for (int i = 0; i < m; i++)
    {
        free(li[i]);
    }
    free(li);
    free(q);
    free(r);
    free(v);

    // Return from the main function
    return 0;
}

