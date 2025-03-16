#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    int i = 1;
    long long ans = 0;

    while (pow(10, i) <= N) {
        ans += (pow(10, i) - pow(10, i - 1));
        i += 2;
    }
    ans += (N - pow(10, i - 1) + 1 > 0) ? (N - pow(10, i - 1) + 1) : 0;

    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
