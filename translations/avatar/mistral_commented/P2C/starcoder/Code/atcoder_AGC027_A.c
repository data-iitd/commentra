
#include <stdio.h>
#include <stdlib.h>

int main( ) {
    int n, x, ans, i;
    scanf("%d %d", &n, &x);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmpfunc);
    ans = 0;
    if (a[0] > x) {
        printf("0\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (a[i] > x) {
            x = 0;
            break;
        }
        x -= a[i];
        ans++;
    }
    if (x!= 0) {
        ans--;
    }
    printf("%d\n", ans);
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

