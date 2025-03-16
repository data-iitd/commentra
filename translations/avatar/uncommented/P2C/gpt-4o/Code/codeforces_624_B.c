#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    double pre = __DBL_MAX__;
    long long ans = 0;
    
    qsort(a, n, sizeof(int), compare); // Sort the array in descending order
    
    for (int j = 0; j < n; j++) {
        ans += (pre - 1 < a[j]) ? (pre - 1) : a[j];
        pre = (pre - 1 < a[j]) ? (pre - 1) : a[j];
    }
    
    printf("%lld\n", ans);
    
    free(a);
    return 0;
}

// <END-OF-CODE>
