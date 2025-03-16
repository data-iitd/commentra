#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n];
    int left = INT_MAX, right = INT_MIN;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] < left) left = a[i];
        if (b[i] > right) right = b[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == left && b[i] == right) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
