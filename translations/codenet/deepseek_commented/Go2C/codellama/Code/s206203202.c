
#include <stdio.h>

int Abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int x = N % K;
    x = min(Abs(x-K), x);
    printf("%d\n", x);

    return 0;
}

