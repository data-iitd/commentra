#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *ar = (int *)malloc(3 * n * sizeof(int));
    
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &ar[i]);
    }
    
    qsort(ar, 3 * n, sizeof(int), compare);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[3 * n - (i + 1) * 2];
    }
    
    printf("%d\n", sum);
    
    free(ar);
    return 0;
}

// <END-OF-CODE>
