#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && i + 2 < n) {
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
                found = 1;
                break;
            }
        }
    }
    printf("%s\n", found ? "YES" : "NO");
    return 0;
}
