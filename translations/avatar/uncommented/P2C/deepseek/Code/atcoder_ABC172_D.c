#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        int div = N / i;
        ans += i * div * (div + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
