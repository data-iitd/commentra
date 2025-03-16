
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long long *ans = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ans[i]);
    }
    qsort(ans, n, sizeof(long long), cmpfunc);
    long long count = ans[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (ans[i] < ans[i + 1]) {
            count += ans[i];
        } else {
            while (ans[i] >= ans[i + 1]) {
                ans[i]--;
            }
            if (ans[i] > 0) {
                count += ans[i];
            }
        }
    }
    printf("%lld\n", count);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(long long*)a - *(long long*)b );
}

