#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int _lcm = 1;
    for (int i = 0; i < N; i++) {
        _lcm = _lcm * A[i] / __gcd(_lcm, A[i]);
    }
    int ans = _lcm * (1 + A[0] + A[1] + A[2] +... + A[N - 1]) % 1000000007;
    printf("%d", ans);
    return 0;
}

