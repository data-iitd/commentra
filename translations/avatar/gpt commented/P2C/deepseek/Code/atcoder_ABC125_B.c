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

    int profit_differences[N + 1];
    profit_differences[0] = 0;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) {
            profit_differences[i + 1] = V[i] - C[i];
        } else {
            profit_differences[i + 1] = 0;
        }
        ans += profit_differences[i + 1];
    }

    printf("%d\n", ans);

    return 0;
}
