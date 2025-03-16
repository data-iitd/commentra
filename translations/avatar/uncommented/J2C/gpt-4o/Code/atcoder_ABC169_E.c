#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int num = 998244353;
    int n;
    scanf("%d", &n);
    
    int *ai = (int *)malloc(n * sizeof(int));
    int *bi = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ai[i], &bi[i]);
    }
    
    qsort(ai, n, sizeof(int), compare);
    qsort(bi, n, sizeof(int), compare);
    
    if (n % 2 == 1) {
        printf("%d\n", bi[n / 2] - ai[n / 2] + 1);
    } else {
        double b = (ai[n / 2] + ai[n / 2 - 1]) / 2.0;
        double c = (bi[n / 2] + bi[n / 2 - 1]) / 2.0;
        printf("%d\n", (int)(2 * (c - b) + 1));
    }
    
    free(ai);
    free(bi);
    
    return 0;
}

// <END-OF-CODE>
