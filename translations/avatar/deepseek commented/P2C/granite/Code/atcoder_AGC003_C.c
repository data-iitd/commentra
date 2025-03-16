
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i] = A[i] * N + i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        if (d % 2!= i % 2) {
            cnt++;
        }
    }

    printf("%d\n", cnt / 2);

    return 0;
}
