
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int tmp = N < M/2? N : M/2;
    int ans = tmp;
    N -= tmp;
    M -= tmp * 2;
    ans += M/4;
    printf("%d\n", ans);
    return 0;
}
