#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10 // Maximum size for n (to limit permutations)

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

void generate_permutations(int *arr, int start, int end, int **perms, int *perm_count) {
    if (start == end) {
        perms[*perm_count] = (int *)malloc(end * sizeof(int));
        memcpy(perms[*perm_count], arr, end * sizeof(int));
        (*perm_count)++;
    } else {
        for (int i = start; i <= end; i++) {
            // Swap
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;

            generate_permutations(arr, start + 1, end, perms, perm_count);

            // Swap back
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    }
}

int find_index(int **perms, int perm_count, int *target, int size) {
    for (int i = 0; i < perm_count; i++) {
        if (memcmp(perms[i], target, size * sizeof(int)) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    int n;
    printf("Enter the size of the permutation list: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int perm_count = factorial(n);
    int **perms = (int **)malloc(perm_count * sizeof(int *));
    for (int i = 0; i < perm_count; i++) {
        perms[i] = (int *)malloc(n * sizeof(int));
    }

    generate_permutations(arr, 0, n - 1, perms, &perm_count);

    int p[MAX_N], q[MAX_N];
    printf("Enter the first permutation: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter the second permutation: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    int pn = find_index(perms, perm_count, p, n);
    int qn = find_index(perms, perm_count, q, n);

    printf("Absolute difference: %d\n", abs(pn - qn));

    // Free allocated memory
    for (int i = 0; i < perm_count; i++) {
        free(perms[i]);
    }
    free(perms);
    free(arr);

    return 0;
}

// <END-OF-CODE>
