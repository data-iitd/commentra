
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

    // int hm[N+1];
    // for (int i = 0; i <= N; i++) {
    //     hm[i] = 0;
    // }
    // while (1) {
    //     if (hm[N] == 1) {
    //         break;
    //     }
    //     hm[N] = 1;
    //     N = Abs(N - K);
    // }
    // int mini = 999999999;
    // for (int i = 0; i <= N; i++) {
    //     if (hm[i] == 1) {
    //         mini = min(mini, i);
    //     }
    // }
    // printf("%d\n", mini);

    int x = N % K;
    x = min(Abs(x - K), x);
    printf("%d\n", x);

    return 0;
}

