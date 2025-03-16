#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k, t;
int *vec;
int ans = 1000000001;

int main() {
    scanf("%d %d", &n, &k);
    vec = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        vec[i] = t;
    }
    qsort(vec, n, sizeof(int), compare);
    for (int i = 0; i + k - 1 < n; i++) {
        int diff = vec[i + k - 1] - vec[i];
        if (diff < ans) {
            ans = diff;
        }
    }
    printf("%d\n", ans);
    free(vec);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

