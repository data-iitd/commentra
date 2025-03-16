#include <stdio.h>
#include <stdlib.h>

// Function to compare two arrays and return 1 if they are equal, otherwise 0
int are_arrays_equal(int* arr1, int* arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the index of a given permutation in the list of all permutations
int find_index(int** orig, int n, int* perm, int size) {
    for (int i = 0; i < size; i++) {
        if (are_arrays_equal(orig[i], perm, n)) {
            return i;
        }
    }
    return -1; // Should never reach here if permutations are unique
}

int main() {
    int n;
    scanf("%d", &n);

    // Calculate the number of permutations
    int size = 1;
    for (int i = 1; i <= n; i++) {
        size *= i;
    }

    // Allocate memory for all permutations
    int** orig = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        orig[i] = (int*)malloc(n * sizeof(int));
    }

    // Generate all possible permutations of the numbers from 1 to n
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int idx = 0;
    do {
        for (int i = 0; i < n; i++) {
            orig[idx][i] = arr[i];
        }
        idx++;
    } while (next_permutation(arr, arr + n));

    // Read the first permutation
    int p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Read the second permutation
    int q[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    // Find the index of the first permutation
    int pn = find_index(orig, n, p, size);

    // Find the index of the second permutation
    int qn = find_index(orig, n, q, size);

    // Calculate and print the absolute difference between the two indices
    printf("%d\n", abs(pn - qn));

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(orig[i]);
    }
    free(orig);
    free(arr);

    return 0;
}
