#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *A = (int *)malloc((2 * n) * sizeof(int));
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &A[i]);
    }

    // Sort the array
    qsort(A, 2 * n, sizeof(int), compare);

    long long ans = 0;
    for (int i = 2 * n - 2; i >= n; i -= 2) {
        ans += A[i];
    }

    printf("%lld\n", ans);
    
    free(A);
    return 0;
}

// <END-OF-CODE>
