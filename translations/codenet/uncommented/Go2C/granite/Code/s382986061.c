
#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int as[N];
    for (int i = 0; i < N; i++) {
        as[i] = 0;
    }
    for (int i = 0; i < K; i++) {
        int d;
        scanf("%d", &d);
        for (int j = 0; j < d; j++) {
            int a;
            scanf("%d", &a);
            as[a - 1]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (as[i] == 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
