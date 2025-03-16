#include <stdio.h>
#include <math.h>

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int floor(int x) {
    return (int)floor((double)x);
}

int main() {
    int N, M, ans = 0;
    scanf("%d %d", &N, &M);
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (N > 1 && M > 1) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    printf("%d\n", ans);
    return 0;
}

