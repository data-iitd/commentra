#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    long int *ans = (long int *)malloc(n * sizeof(long int));
    for (int i = 0; i < n; i++) {
        scanf("%ld", &ans[i]);
    }
    qsort(ans, n, sizeof(long int), compare);
    long int count = ans[n - 1];
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
    printf("%ld\n", count);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(long int *)a - *(long int *)b);
}

