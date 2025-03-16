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
        for (int i = N - 1; i <= X + 1; i++) {
            printf("%d\n", i);
        }
        for (int i = 1; i < N - 1; i++) {
            printf("%d\n", i);
        }
    } else {
        int ys[N * 2];
        for (int i = 0; i < N * 2; i++) {
            ys[i] = i + 1;
        }
        for (int i = 0; i < X - 2; i++) {
            printf("%d\n", ys[i]);
        }
        printf("%d\n", X + 2);
        printf("%d\n", X - 1);
        printf("%d\n", X);
        printf("%d\n", X + 1);
        for (int i = X + 3; i < N * 2; i++) {
            printf("%d\n", ys[i]);
        }
    }

    return 0;
}
