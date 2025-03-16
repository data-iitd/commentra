#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);

    int a[x], b[y], c[z];

    for (int i = 0; i < x; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < y; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < z; i++) {
        scanf("%d", &c[i]);
    }

    // Initialize an empty list to store the sums of elements from lists a and b
    int *ab = (int *)malloc(x * y * sizeof(int));
    int ab_size = 0;

    // Calculate all possible sums of elements from list a and list b
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[ab_size++] = a[i] + b[j];
        }
    }

    // Sort the list of sums in descending order
    qsort(ab, ab_size, sizeof(int), (int (*)(const void *, const void *))compare_desc);

    // Initialize an empty list to store the sums of the top k elements from ab and elements from list c
    int *abc = (int *)malloc(k * z * sizeof(int));
    int abc_size = 0;

    // Calculate sums of the top k elements from ab with each element in c
    for (int i = 0; i < (k < ab_size ? k : ab_size); i++) {
        for (int j = 0; j < z; j++) {
            abc[abc_size++] = ab[i] + c[j];
        }
    }

    // Sort the resulting sums in descending order
    qsort(abc, abc_size, sizeof(int), (int (*)(const void *, const void *))compare_desc);

    // Print the top k sums from the final list abc
    for (int i = 0; i < k; i++) {
        printf("%d\n", abc[i]);
    }

    // Free allocated memory
    free(ab);
    free(abc);

    return 0;
}

int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
