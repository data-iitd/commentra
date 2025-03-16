#include <stdio.h>

int main() {
    int N;
    // Reading input
    scanf("%d", &N);
    int a[N];
    
    // Reading the array elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // Calculating the XOR of all elements in the array 'a'
    int total = 0;
    for (int i = 0; i < N; i++) {
        total ^= a[i];
    }

    // Printing the result
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
