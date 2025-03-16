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
    int xs[N];
    if (X == N * 2 - 2) {
        for (int i = 0; i < N - 1; i++) {
            xs[i] = N - 1 - i;
        }
        for (int i = N - 1; i < X + 2; i++) {
            xs[i] = i - N + 2;
        }
        for (int i = 1; i < N - 1; i++) {
            xs[X + 2 + i] = i;
        }
    } else {
        for (int i = 0; i < X - 1; i++) {
            xs[i] = i + 1;
        }
        for (int i = X + 3; i <= N * 2; i++) {
            xs[i - 3] = i;
        }
        xs[X - 1] = X + 2;
        xs[X] = X;
        xs[X + 1] = X + 1;
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", xs[i]);
    }

    return 0;
}
