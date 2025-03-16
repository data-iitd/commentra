#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    qsort(a, n, sizeof(int), compare);

    bool found = false;
    for (int i = 0; i < n - 2; i++) {
        if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
            found = true;
            break;
        }
    }

    printf(found ? "YES\n" : "NO\n");
    return 0;
}
