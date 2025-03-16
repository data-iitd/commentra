#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int total = 0;
    for (int i = 0; i < N; i++) {
        total ^= a[i];
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i] ^ total);
    }
    printf("\n");
    return 0;
}

