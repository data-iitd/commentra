
#include <stdio.h>
#include <stdlib.h>

// Function to calculate XOR of all elements in the array
int xor_all(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = result ^ arr[i];
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int total = xor_all(a, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", a[i] ^ total);
    }
    printf("\n");

    return 0;
}

