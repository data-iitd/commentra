#include <stdio.h>

int main() {
    // Step 1: Take an integer input N, which represents the number of elements in the list.
    int N;
    scanf("%d", &N);

    // Step 2: Take a list of integers as input and store them in the array 'a'.
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // Step 3: Calculate the total XOR of all elements in the array 'a'.
    int total = 0;
    for (int i = 0; i < N; i++) {
        total ^= a[i];
    }

    // Step 4: Create a new list where each element is the XOR of the original element and the total.
    // Print the new list as a space-separated string.
    for (int i = 0; i < N; i++) {
        printf("%d", a[i] ^ total);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
