#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000  // Define a maximum size for the array

int main() {
    int N;
    scanf("%d", &N);  // Reading number of elements

    int A[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);  // Reading list of elements
    }

    // Removing consecutive duplicates from list A
    int B[MAX_N];
    int newN = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != A[i - 1]) {
            B[newN++] = A[i];  // Store unique elements
        }
    }

    N = newN;  // Update N to reflect the new length of B
    int ans = 0;

    // Main logic to find peaks
    for (int i = 1; i < N - 1; ) {
        if ((B[i - 1] < B[i] && B[i] > B[i + 1]) || (B[i - 1] > B[i] && B[i] < B[i + 1])) {
            ans += 1;
            i += 2;  // Skip next element as it's already checked
        } else {
            i += 1;
        }
    }

    // Output the total number of peaks found
    printf("%d\n", ans + 1);

    return 0;
}
