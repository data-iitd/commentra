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
    int index = 0;

    // Calculate sums of a[i] + b[j]
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[index++] = a[i] + b[j];
        }
    }

    // Sort ab in descending order
    qsort(ab, x * y, sizeof(int), compare);

    int *abc = (int *)malloc(k * z * sizeof(int));
    index = 0;

    // Calculate sums of ab[i] + c[j]
    for (int i = 0; i < (k < x * y ? k : x * y); i++) {
        for (int j = 0; j < z; j++) {
            abc[index++] = ab[i] + c[j];
        }
    }

    // Sort abc in descending order
    qsort(abc, index, sizeof(int), compare);

    // Print the first k elements of abc
    for (int i = 0; i < k && i < index; i++) {
        printf("%d\n", abc[i]);
    }

    // Free allocated memory
    free(a);
    free(b);
    free(c);
    free(ab);
    free(abc);

    return 0;
}

// <END-OF-CODE>
