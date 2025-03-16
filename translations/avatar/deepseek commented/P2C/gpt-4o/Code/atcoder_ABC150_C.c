#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_permutations(int *arr, int n, int **perms, int *count) {
    if (n == 1) {
        perms[*count] = (int *)malloc(sizeof(int) * (*count + 1));
        memcpy(perms[*count], arr, sizeof(int) * (*count + 1));
        (*count)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        generate_permutations(arr, n - 1, perms, count);
        if (n % 2 == 0) {
            int temp = arr[i];
            arr[i] = arr[n - 1];
            arr[n - 1] = temp;
        } else {
            int temp = arr[0];
            arr[0] = arr[n - 1];
            arr[n - 1] = temp;
        }
    }
}

int find_index(int **perms, int count, int *perm, int n) {
    for (int i = 0; i < count; i++) {
        if (memcmp(perms[i], perm, sizeof(int) * n) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    int n;
    scanf("%d", &n); // Take an integer input `n`

    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // Fill array with numbers from 1 to n
    }

    int **perms = (int **)malloc(sizeof(int *) * 720); // 720 is 6! (for n=6)
    int count = 0;
    generate_permutations(arr, n, perms, &count); // Generate all permutations

    int *p = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); // Take the first permutation `p`
    }

    int *q = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]); // Take the second permutation `q`
    }

    int pn = find_index(perms, count, p, n); // Find index of permutation `p`
    int qn = find_index(perms, count, q, n); // Find index of permutation `q`

    printf("%d\n", abs(pn - qn)); // Print the absolute difference

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(perms[i]);
    }
    free(perms);
    free(arr);
    free(p);
    free(q);

    return 0;
}
