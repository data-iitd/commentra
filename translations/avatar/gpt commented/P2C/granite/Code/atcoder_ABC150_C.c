
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read an integer input n, which defines the range of numbers to permute
    int n;
    scanf("%d", &n);

    // Generate all possible permutations of the numbers from 1 to n
    int *orig = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        orig[i] = i + 1;
    }

    // Read the first permutation input as an array of integers
    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Read the second permutation input as an array of integers
    int *q = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    // Find the index of the first permutation in the list of all permutations
    int pn = 0;
    for (int i = 0; i < n; i++) {
        int same = 1;
        for (int j = 0; j < n; j++) {
            if (orig[i * n + j]!= p[j]) {
                same = 0;
                break;
            }
        }
        if (same) {
            pn = i;
            break;
        }
    }

    // Find the index of the second permutation in the list of all permutations
    int qn = 0;
    for (int i = 0; i < n; i++) {
        int same = 1;
        for (int j = 0; j < n; j++) {
            if (orig[i * n + j]!= q[j]) {
                same = 0;
                break;
            }
        }
        if (same) {
            qn = i;
            break;
        }
    }

    // Calculate and print the absolute difference between the two indices
    printf("%d\n", abs(pn - qn));

    // Free the memory allocated for the arrays
    free(orig);
    free(p);
    free(q);

    return 0;
}
