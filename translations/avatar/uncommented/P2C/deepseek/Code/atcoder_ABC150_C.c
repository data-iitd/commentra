#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *arr, int l, int r, int **result, int *index) {
    if (l == r) {
        result[*index] = (int *)malloc(r * sizeof(int));
        memcpy(result[*index], arr, r * sizeof(int));
        (*index)++;
    } else {
        for (int i = l; i <= r; i++) {
            swap(&arr[l], &arr[i]);
            permute(arr, l + 1, r, result, index);
            swap(&arr[l], &arr[i]); // backtrack
        }
    }
}

int find_index(int **arr, int size, int *target) {
    for (int i = 0; i < size; i++) {
        if (memcmp(arr[i], target, size * sizeof(int)) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        arr[i - 1] = i;
    }

    int **result = (int **)malloc(factorial(n) * sizeof(int *));
    int index = 0;
    permute(arr, 0, n - 1, result, &index);

    int *p = (int *)malloc(n * sizeof(int));
    int *q = (int *)malloc(n * sizeof(int));
    scanf("%d %d %d", &p[0], &p[1], &p[2]);
    scanf("%d %d %d", &q[0], &q[1], &q[2]);

    int pn = find_index(result, factorial(n), p);
    int qn = find_index(result, factorial(n), q);

    printf("%d\n", abs(pn - qn));

    for (int i = 0; i < index; i++) {
        free(result[i]);
    }
    free(result);
    free(arr);
    free(p);
    free(q);

    return 0;
}

