
#include <stdio.h>
#include <math.h>

int main() {
    int N, M, ans = 0;
    scanf("%d %d", &N, &M);
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }
    printf("%d\n", ans);
    return 0;
}

