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

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int **perms = (int **)malloc(720 * sizeof(int *)); // 720 is 6! (for n=6)
    int count = 0;
    generate_permutations(arr, n, perms, &count);

    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    int *q = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    int pn = -1, qn = -1;
    for (int i = 0; i < count; i++) {
        if (memcmp(perms[i], p, n * sizeof(int)) == 0) {
            pn = i;
        }
        if (memcmp(perms[i], q, n * sizeof(int)) == 0) {
            qn = i;
        }
    }

    printf("%d\n", abs(pn - qn));

    for (int i = 0; i < count; i++) {
        free(perms[i]);
    }
    free(perms);
    free(arr);
    free(p);
    free(q);

    return 0;
}
