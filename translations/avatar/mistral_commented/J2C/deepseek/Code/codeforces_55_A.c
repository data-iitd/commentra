#include <stdio.h>

int main() {
    int n, i = 1, k = 0, p = 1;
    int a[1000] = {0};
    scanf("%d", &n);

    while (k <= n) {
        i += k;
        if (i >= n) {
            while (i >= n) i -= n;
        }
        a[i]++;
        k++;
    }

    for (i = 0; i < n; ++i) {
        if (a[i] == 0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}

