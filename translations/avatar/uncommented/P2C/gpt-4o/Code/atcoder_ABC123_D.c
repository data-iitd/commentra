#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a; // Sort in descending order
}

int main() {
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);
    
    int *a = (int *)malloc(x * sizeof(int));
    int *b = (int *)malloc(y * sizeof(int));
    int *c = (int *)malloc(z * sizeof(int));
    
    for (int i = 0; i < x; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < y; i++) {
        scanf("%d", &b[i]);
    }
    
    for (int i = 0; i < z; i++) {
        scanf("%d", &c[i]);
    }
    
    int *ab = (int *)malloc(x * y * sizeof(int));
    int ab_size = 0;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[ab_size++] = a[i] + b[j];
        }
    }
    
    qsort(ab, ab_size, sizeof(int), compare);
    
    int *abc = (int *)malloc(k * z * sizeof(int));
    int abc_size = 0;
    
    for (int i = 0; i < (k < ab_size ? k : ab_size); i++) {
        for (int j = 0; j < z; j++) {
            abc[abc_size++] = ab[i] + c[j];
        }
    }
    
    qsort(abc, abc_size, sizeof(int), compare);
    
    for (int i = 0; i < k; i++) {
        printf("%d\n", abc[i]);
    }
    
    free(a);
    free(b);
    free(c);
    free(ab);
    free(abc);
    
    return 0;
}

// <END-OF-CODE>
