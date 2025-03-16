#include <stdio.h>

int main()
{
    int N, i, X, Y, ans = 0;
    int V[100], C[100];
    int list[100];

    // Read the number of test cases
    scanf("%d", &N);

    // Read the array V of size N
    for (i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // Read the array C of size N
    for (i = 0; i < N; i++)
    {
        scanf("%d", &C[i]);
    }

    // Initialize an empty list to store the differences between V and C
    for (i = 0; i < N; i++)
    {
        list[i] = 0;
    }

    // Initialize variables to store the current difference and the sum of differences
    X = 0;
    Y = 0;

    // Iterate through each index i from 0 to N-1
    for (i = 0; i < N; i++)
    {
        // If the difference between V[i] and C[i] is positive
        if (V[i] - C[i] > 0)
        {
            // Update X and Y with the respective values from V and C at index i
            X = V[i];
            Y = C[i];
            // Append the difference X-Y to the list
            list[i] = X - Y;
            // Update the sum of differences
            ans += X - Y;
        }
    }

    // Print the sum of all the elements in the list
    for (i = 0; i < N; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    // Print the sum of all the differences between V and C
    printf("%d\n", ans);

    return 0;
}
