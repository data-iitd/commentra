#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF (int)1e9
#define mod 1000000007

int input() {
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {
    int N = input();
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = input();
    }

    // Remove consecutive duplicates
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != A[i - 1]) {
            A[k++] = A[i];
        }
    }
    N = k;

    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;
            i++;
        }
    }
    printf("%d\n", ans + 1);

    return 0;
}
