#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);

    // Assuming a, b, c are defined somewhere in the code
    // For the sake of this example, let's assume they are defined as arrays
    int a[x * y], b[y * z], c[z * x];

    // Read input for a and b
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &a[i * y + j]);
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < z; j++) {
            scanf("%d", &b[i * z + j]);
        }
    }
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < x; j++) {
            scanf("%d", &c[i * x + j]);
        }
    }

    // Initialize an empty array ab to store the sum of each element from a with each element from b
    int *ab = (int *)malloc(x * y * sizeof(int));
    int ab_index = 0;

    // Iterate through each element in a and b, and store their sum in ab
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[ab_index++] = a[i * y + j] + b[j * z + i];
        }
    }

    // Sort array ab in descending order
    qsort(ab, x * y, sizeof(int), (int (*)(const void *, const void *))compare_desc);

    // Initialize an empty array abc to store the sum of each element from ab with each element from c
    int *abc = (int *)malloc(k * sizeof(int));
    int abc_index = 0;

    // Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to abc
    for (int i = 0; i < min(k, x * y); i++) {
        for (int j = 0; j < z; j++) {
            abc[abc_index++] = ab[i] + c[j * x + i];
        }
    }

    // Sort array abc in descending order
    qsort(abc, k, sizeof(int), (int (*)(const void *, const void *))compare_desc);

    // Iterate through the first k elements of array abc and print each element
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
