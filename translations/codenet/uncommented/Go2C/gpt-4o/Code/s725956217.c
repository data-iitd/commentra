#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} shop;

int compare(const void *x, const void *y) {
    return ((shop *)x)->a - ((shop *)y)->a;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    shop *s = (shop *)malloc(N * sizeof(shop));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s[i].a, &s[i].b);
    }
    
    qsort(s, N, sizeof(shop), compare);
    
    int total = 0;
    for (int i = 0; i < N; i++) {
        int n = (s[i].b < M) ? s[i].b : M;
        total += n * s[i].a;
        M -= n;
        if (M == 0) {
            break;
        }
    }
    
    printf("%d\n", total);
    
    free(s);
    return 0;
}

// <END-OF-CODE>
