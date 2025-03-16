#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    qsort(a, n, sizeof(int), compare);
    
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i] * 2 && a[i] != a[i + 1]) {
            printf("YES\n");
            free(a);
            return 0;
        }
    }
    
    printf("NO\n");
    free(a);
    return 0;
}

// <END-OF-CODE>
