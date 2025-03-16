
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    if (possible(N, A)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

int possible(int N, int A[]) {
    long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    long NS = (long) N * (N + 1) / 2;
    if (sum % NS != 0) {
        return 0;
    }
    long K = sum / NS;
    for (int i = 0; i < N; i++) {
        int j = i == 0 ? N - 1 : i - 1;
        long d = K - (A[i] - A[j]);
        if (d < 0 || d % N != 0) {
            return 0;
        }
    }
    return 1;
}

