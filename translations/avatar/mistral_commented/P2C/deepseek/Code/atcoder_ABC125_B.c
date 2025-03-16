#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int V[N], C[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }

    int list[N];
    int ans = 0, X = 0, Y = 0;

    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) {
            X = V[i];
            Y = C[i];
            list[i] = X - Y;
            ans += X - Y;
        } else {
            list[i] = 0;
        }
    }

    int sum_list = 0;
    for (int i = 0; i < N; i++) {
        sum_list += list[i];
    }

    printf("%d\n", sum_list);
    printf("%d\n", ans);

    return 0;
}
