
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 1: Take an integer input N, which represents the number of elements in the list.
    int N;
    scanf("%d", &N);

    // Step 2: Take a list of integers as input and store them in the array 'a'.
    int *a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // Step 3: Calculate the total XOR of all elements in the array 'a' using reduce and XOR operator.
    int total = 0;
    for (int i = 0; i < N; i++) {
        total ^= a[i];
    }

    // Step 4: Create a new array where each element is the XOR of the original element and the total.
    // Print the new array as a space-separated string.
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i] ^ total);
    }

    // Free the memory allocated for the array 'a'.
    free(a);

    return 0;
}
