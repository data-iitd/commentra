#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, X;
    scanf("%d %d", &N, &X);
    // Comment: Read input values N and X from the standard input

    int *xs;
    if (X == 1 || X == N * 2 - 1)
    {
        printf("No\n");
        // If X is equal to 1 or N*2-1, print "No"
    }
    else
    {
        printf("Yes\n");
        // Else, X is neither 1 nor N*2-1

        if (X == N * 2 - 2)
        {
            xs = (int *)malloc(N * sizeof(int));
            for (int i = 0; i < N - 1; i++)
            {
                xs[i] = N - 1 - i;
            }
            for (int i = N - 1; i < N * 2 - 1; i++)
            {
                xs[i] = i - N + 1;
            }
            // Calculate the list xs based on the value of X
        }
        else
        {
            xs = (int *)malloc(N * sizeof(int));
            for (int i = 0; i < N - 3; i++)
            {
                xs[i] = i + 1;
            }
            xs[N - 3] = X + 2;
            xs[N - 2] = X - 1;
            xs[N - 1] = X;
            xs[N] = X + 1;
            for (int i = N + 1; i < N * 2 - 1; i++)
            {
                xs[i] = i - N + 1;
            }
            // Calculate the list xs based on the value of X
        }

        for (int i = 0; i < N * 2 - 1; i++)
        {
            printf("%d ", xs[i]);
            // Print each element of the list xs
        }
    }

    free(xs);
    // Free the memory allocated for the list xs

    return 0;
}

