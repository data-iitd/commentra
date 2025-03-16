#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 100000

int main() {
    int N;
    scanf("%d", &N);
    int A[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if (A[i - 1] < A[i] > A[i + 1] || A[i - 1] > A[i] < A[i + 1]) {
            ans++;
            i++;
        }
    }
    i++;
    printf("%d", ans + 1);
    return 0;
}

