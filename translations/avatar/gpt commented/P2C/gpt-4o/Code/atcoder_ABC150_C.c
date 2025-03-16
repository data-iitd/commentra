#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate_permutations(int *arr, int start, int end, int **perms, int *count) {
    if (start == end) {
        perms[*count] = (int *)malloc((end + 1) * sizeof(int));
        memcpy(perms[*count], arr, (end + 1) * sizeof(int));
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            generate_permutations(arr, start + 1, end, perms, count);
            swap(&arr[start], &arr[i]); // backtrack
        }
    }
}

int find_index(int **perms, int count, int *perm, int size) {
    for (int i = 0; i < count; i++) {
        if (memcmp(perms[i], perm, size * sizeof(int)) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int **perms = (int **)malloc(720 * sizeof(int *)); // 720 is 6! (for n=6)
    int count = 0;
    generate_permutations(arr, 0, n - 1, perms, &count);

    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    int *q = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    int pn = find_index(perms, count, p, n);
    int qn = find_index(perms, count, q, n);

    printf("%d\n", abs(pn - qn));

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

// <END-OF-CODE>
