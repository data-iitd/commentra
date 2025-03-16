#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    qsort(l, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        if (l[i] + 1 <= l[n - 1] && l[i] + 2 <= l[n - 1]) {
            if (binary_search(l, l + n, l[i] + 1) && binary_search(l, l + n, l[i] + 2)) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}

