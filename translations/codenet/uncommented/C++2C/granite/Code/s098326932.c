

#include<stdio.h>

int main() {
    int K;
    scanf("%d", &K);
    int N = 1;
    for (int i = 0; i < K; i++) {
        printf("%d\n", N);
        N++;
    }
    return 0;
}
