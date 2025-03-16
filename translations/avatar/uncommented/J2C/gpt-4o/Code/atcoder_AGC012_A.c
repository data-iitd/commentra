#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *array = (int *)malloc(3 * n * sizeof(int));
    
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &array[i]);
    }
    
    qsort(array, 3 * n, sizeof(int), compare);
    
    int head = 3 * n - 2;
    long long res = 0;
    
    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }
    
    printf("%lld\n", res);
    
    free(array);
    return 0;
}

// <END-OF-CODE>
