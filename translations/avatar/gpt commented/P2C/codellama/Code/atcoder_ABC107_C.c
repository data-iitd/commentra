#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, K, i, j, p, m, x, y, lastx, lasty, ans;
    int *lst, *lst_p, *lst_m;

    // Read two integers N and K from input
    scanf("%d %d", &N, &K);

    // Allocate memory for the list of integers
    lst = (int *)malloc(N * sizeof(int));
    lst_p = (int *)malloc(N * sizeof(int));
    lst_m = (int *)malloc(N * sizeof(int));

    // Read a list of integers from input
    for (i = 0; i < N; i++)
    {
        scanf("%d", &lst[i]);
    }

    // Initialize lists to hold positive and negative numbers
    lastx = 0;
    lasty = 0;
    for (i = 0; i < N; i++)
    {
        // Decrease K for each zero encountered
        if (lst[i] == 0)
        {
            K--;
        }
        // Add positive numbers to lst_p
        if (lst[i] > 0)
        {
            lst_p[lastx++] = lst[i];
        }
        // Add negative numbers to lst_m
        else if (lst[i] < 0)
        {
            lst_m[lasty++] = lst[i];
        }
    }

    // Initialize variables to track the last indices of positive and negative lists
    p = 0;
    m = 0;
    x = 0;
    y = lasty - 1;

    // Define a function to check the minimum value based on K
    ans = 1000000000;
    for (j = 0; j <= K; j++)
    {
        // Check if the current count of positives and negatives is valid
        if (j > lastx || K - j > lasty)
        {
            continue;
        }
        else
        {
            // Determine the maximum positive number used
            if (j == 0)
            {
                p = 0;
            }
            else
            {
                p = lst_p[j - 1];
            }

            // Determine the maximum negative number used
            if (K - j == 0)
            {
                m = 0;
            }
            else
            {
                m = lst_m[lasty - (K - j)];
            }

            // Calculate the minimum value based on the current combination
            ans = min(ans, 2 * p + abs(m), p + 2 * abs(m));
        }
    }

    // Print the result of the check function with K
    printf("%d\n", ans);

    // Free memory
    free(lst);
    free(lst_p);
    free(lst_m);

    return 0;
}

