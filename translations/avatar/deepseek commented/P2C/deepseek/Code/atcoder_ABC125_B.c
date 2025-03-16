#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);  // Taking an integer input N, which represents the number of elements.

    int V[N], C[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);  // Taking the first line of space-separated integers and storing them in array V.
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);  // Taking the second line of space-separated integers and storing them in array C.
    }

    int ans = 0;
    int list[1] = {0};

    // Entering a for loop that iterates N times.
    for (int i = 0; i < N; i++) {
        // Checking if the difference between the i-th element of V and the i-th element of C is greater than 0.
        if (V[i] - C[i] > 0) {
            int X = V[i];  // Assigning the i-th element of V to X.
            int Y = C[i];  // Assigning the i-th element of C to Y.
            int temp = X - Y;  // Calculating the difference X - Y.
            // Reallocating memory for list to accommodate the new element.
            list[0] = 0;  // Resetting the list to a single element 0.
            list = (int*)realloc(list, (ans + 1) * sizeof(int));  // Reallocating memory.
            list[ans] = temp;  // Assigning the difference X - Y to the list.
            ans++;  // Incrementing the ans.
        }
    }

    // Calculating the sum of the list.
    int sum = 0;
    for (int i = 0; i < ans; i++) {
        sum += list[i];
    }

    // Printing the sum of the list.
    printf("%d\n", sum);

    // Freeing the allocated memory.
    free(list);

    return 0;
}
