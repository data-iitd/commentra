
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read input: four integers x, y, z, and k followed by x * y integers each for lists a, b, and c
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);

    // Initialize an empty array ab to store the sum of each element from list a with each element from list b
    int *ab = (int *)malloc(x * y * sizeof(int));
    int ab_size = 0;

    // Iterate through each element in list a for i, and for each element in list b for j, append their sum to array ab
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[ab_size++] = a[i] + b[j];
        }
    }

    // Sort array ab in descending order
    qsort(ab, ab_size, sizeof(int), cmpfunc);

    // Initialize an empty array abc to store the sum of each element from array ab with each element from list c
    int *abc = (int *)malloc(k * sizeof(int));
    int abc_size = 0;

    // Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to array abc
    for (int i = 0; i < (k < x * y? k : x * y); i++) {
        for (int j = 0; j < z; j++) {
            abc[abc_size++] = ab[i] + c[j];
        }
    }

    // Sort array abc in descending order
    qsort(abc, abc_size, sizeof(int), cmpfunc);

    // Iterate through the first k elements of array abc and print each element
    for (int i = 0; i < k; i++) {
        printf("%d\n", abc[i]);
    }

    // Free memory allocated for arrays ab and abc
    free(ab);
    free(abc);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

