#include <stdio.h>

int main() {
    int N, K, d, a;
    int as[1000001];
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        as[i] = 0;
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &d);
        for (int j = 0; j < d; j++) {
            scanf("%d", &a);
            as[a]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (as[i] == 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
