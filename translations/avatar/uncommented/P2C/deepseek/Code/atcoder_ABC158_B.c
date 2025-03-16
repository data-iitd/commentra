#include <stdio.h>

int main() {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    int mod = 1000000007;
    int ans = 0;
    int rep = N / (A + B);
    ans += rep * A;
    int res = N - rep * (A + B);
    ans += res < A ? res : A;
    printf("%d\n", ans);
    return 0;
}

