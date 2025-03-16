
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int K;
    scanf("%d", &K);
    int N = 1;
    for (int i = 0; i < K; i++) {
        printf("%d\n", N);
        N = (int) (N * 10.0 / (9.0 * (log10(N) + 1.0)));
    }
}

