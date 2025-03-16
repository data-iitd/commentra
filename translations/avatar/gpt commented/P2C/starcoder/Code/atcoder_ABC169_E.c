#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    int *low = malloc(sizeof(int) * n);
    int *high = malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &low[i], &high[i]);
    }
    
    qsort(low, n, sizeof(int), cmpfunc);
    qsort(high, n, sizeof(int), cmpfunc);
    
    if (n % 2) {
        printf("%d\n", high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
    } else {
        printf("%d\n", (high[n / 2 - 1] + high[n / 2]) / 2 - (low[n / 2 - 1] + low[n / 2]) / 2 + 1);
    }
    
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

