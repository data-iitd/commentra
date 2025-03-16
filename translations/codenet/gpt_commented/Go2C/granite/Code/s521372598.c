
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int x[n];
    for (int i = 0; i < n; i++) {
        x[i] = a[i] - i + 1;
    }
    qsort(x, n, sizeof(int), cmpfunc);
    int b = x[n/2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(x[i] - b);
    }
    printf("%d\n", ans);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// 