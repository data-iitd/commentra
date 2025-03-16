#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k, t;
    scanf("%d %d", &n, &k);
    int vec[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        vec[i] = t;
    }
    qsort(vec, n, sizeof(int), compare);
    int ans = 1000000001;
    for (int i = 0; i + k - 1 < n; i++) {
        int diff = vec[i + k - 1] - vec[i];
        if (diff < ans) {
            ans = diff;
        }
    }
    printf("%d\n", ans);
}
