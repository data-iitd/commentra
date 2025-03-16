#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a; // Sort in descending order
}

int main() {
    int x, y, z, k;
    
    // Read integers x, y, z, and k from input
    scanf("%d %d %d %d", &x, &y, &z, &k);
    
    // Read list a of size x from input
    int *a = (int *)malloc(x * sizeof(int));
    for (int i = 0; i < x; i++) {
        scanf("%d", &a[i]);
    }
    
    // Read list b of size y from input
    int *b = (int *)malloc(y * sizeof(int));
    for (int i = 0; i < y; i++) {
        scanf("%d", &b[i]);
    }
    
    // Read list c of size z from input
    int *c = (int *)malloc(z * sizeof(int));
    for (int i = 0; i < z; i++) {
        scanf("%d", &c[i]);
    }
    
    // Initialize an array to store the sums of elements from lists a and b
    int *ab = (int *)malloc(x * y * sizeof(int));
    int ab_size = 0;

    // Calculate all possible sums of elements from list a and list b
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[ab_size++] = a[i] + b[j];
        }
    }

    // Sort the list of sums in descending order
    qsort(ab, ab_size, sizeof(int), compare);

    // Initialize an array to store the sums of the top k elements from ab and elements from list c
    int *abc = (int *)malloc(k * z * sizeof(int));
    int abc_size = 0;

    // Calculate sums of the top k elements from ab with each element in c
    for (int i = 0; i < (k < ab_size ? k : ab_size); i++) {
        for (int j = 0; j < z; j++) {
            abc[abc_size++] = ab[i] + c[j];
        }
    }

    // Sort the resulting sums in descending order
    qsort(abc, abc_size, sizeof(int), compare);

    // Print the top k sums from the final list abc
    for (int i = 0; i < k; i++) {
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
