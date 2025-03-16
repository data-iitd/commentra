#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    int ans = 0;

    if (a[0] > x) {
        printf("0\n");
        free(a);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            x = 0;
            break;
        }
        x -= a[i];
        ans++;
    }

    if (x != 0) {
        ans--;
    }

    printf("%d\n", ans);
    free(a);
    return 0;
}
