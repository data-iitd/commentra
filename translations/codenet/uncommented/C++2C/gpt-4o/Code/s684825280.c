#include <stdio.h>
#include <stdlib.h>

#define SIZE ((int)(1e5 * 2) + 13)

int cnt[SIZE];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    
    int *a = (int *)malloc(SIZE * sizeof(int));
    int a_size = 0;
    
    for (int i = 0; i < SIZE; ++i) {
        if (cnt[i] > 0) {
            a[a_size++] = cnt[i];
        }
    }
    
    int ans = 0;
    qsort(a, a_size, sizeof(int), compare);
    
    int m = a_size - k;
    for (int i = 0; i < m; ++i) {
        ans += a[i];
    }
    
    printf("%d\n", ans);
    
    free(a);
    return 0;
}

// <END-OF-CODE>
