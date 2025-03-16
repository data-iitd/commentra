#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main() {
    int N;
    scanf("%d", &N);
    
    int A[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Remove duplicates
    int uniqueA[MAX_N];
    int uniqueN = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != A[i - 1]) {
            uniqueA[uniqueN++] = A[i];
        }
    }

    N = uniqueN;
    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if ((uniqueA[i - 1] < uniqueA[i] && uniqueA[i] > uniqueA[i + 1]) ||
            (uniqueA[i - 1] > uniqueA[i] && uniqueA[i] < uniqueA[i + 1])) {
            ans++;
            i++; // Skip the next element
        }
    }

    printf("%d\n", ans + 1);
    return 0;
}

// <END-OF-CODE>
