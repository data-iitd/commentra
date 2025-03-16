#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);  // Taking an integer input N, which represents the number of elements.

    int *V = (int *)malloc(N * sizeof(int));  // Dynamically allocating memory for array V.
    int *C = (int *)malloc(N * sizeof(int));  // Dynamically allocating memory for array C.

    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);  // Taking the first line of space-separated integers and storing them in array V.
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);  // Taking the second line of space-separated integers and storing them in array C.
    }

    int *list = (int *)malloc((N + 1) * sizeof(int));  // Dynamically allocating memory for list.
    list[0] = 0;  // Initializing the first element of list to 0.
    int ans = 0;
    int X = 0;
    int Y = 0;

    // Entering a for loop that iterates N times.
    for (int i = 0; i < N; i++) {
        // Checking if the difference between the i-th element of V and the i-th element of C is greater than 0.
        if (V[i] - C[i] > 0) {
            X = V[i];  // Assigning the i-th element of V to X.
            Y = C[i];  // Assigning the i-th element of C to Y.
            list[++ans] = X - Y;  // Appending the difference X - Y to the list.
        }
    }

    // Printing the sum of the list.
    int sum = 0;
    for (int i = 0; i <= ans; i++) {
        sum += list[i];
    }
    printf("%d\n", sum);

    // Freeing allocated memory.
    free(V);
    free(C);
    free(list);

    return 0;
}

// <END-OF-CODE>
