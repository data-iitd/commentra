
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int *V;
    int *C;
    int *list;
    int ans;
    int X;
    int Y;

    // Taking an integer input N, which represents the number of elements.
    scanf("%d", &N);

    // Allocating memory for V and C.
    V = (int *)malloc(N * sizeof(int));
    C = (int *)malloc(N * sizeof(int));

    // Taking the first line of space-separated integers and storing them in list V.
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // Taking the second line of space-separated integers and storing them in list C.
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &C[i]);
    }

    // Initializing a list named list with a single element 0 and an integer ans set to 0.
    list = (int *)malloc(1 * sizeof(int));
    list[0] = 0;
    ans = 0;
    X = 0;
    Y = 0;

    // Entering a for loop that iterates N times.
    for (int i = 0; i < N; i++)
    {
        // Checking if the difference between the i-th element of V and the i-th element of C is greater than 0.
        if (V[i] - C[i] > 0)
        {
            X = V[i]; // Assigning the i-th element of V to X.
            Y = C[i]; // Assigning the i-th element of C to Y.
            list[i] = X - Y; // Appending the difference X - Y to the list.
        }
    }

    // Printing the sum of the list.
    for (int i = 0; i < N; i++)
    {
        ans += list[i];
    }
    printf("%d", ans);

    // Freeing the memory allocated for V, C, and list.
    free(V);
    free(C);
    free(list);

    return 0;
}

