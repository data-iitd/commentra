#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    if (X == 1 || X == N * 2 - 1) {
        printf("No\n");
        return 0;
    }

    printf("Yes\n");

    if (X == N * 2 - 2) {
        int xs[N];
        for (int i = 0; i < N - 1; i++) {
            xs[i] = N - 1 + i + 1;
        }
        for (int i = 0; i < N - 2; i++) {
            printf("%d\n", xs[i]);
        }
        printf("%d\n%d\n%d\n%d\n", X + 2, X - 1, X, X + 1);
        for (int i = N - 3; i >= 0; i--) {
            printf("%d\n", xs[i]);
        }
    } else {
        int ys[N * 2 - 2];
        for (int i = 0; i < X - 2; i++) {
            ys[i] = i + 1;
        }
        for (int i = X; i < N * 2 - 2; i++) {
            ys[i] = i + 1;
        }
        int xs[N];
        for (int i = 0; i < N - 3; i++) {
            xs[i] = ys[i];
        }
        xs[N - 3] = X + 2;
        xs[N - 2] = X - 1;
        xs[N - 1] = X;
        xs[N] = X + 1;
        for (int i = N - 3; i < N * 2 - 2; i++) {
            xs[i + 1] = ys[i];
        }
        for (int i = 0; i < N; i++) {
            printf("%d\n", xs[i]);
        }
    }

    return 0;
}
