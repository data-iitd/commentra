#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int f = 0;
    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k, j, i;
    for (k = 0; k < n; k++) {
        int t = a[k];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j && t == (a[i] + a[j])) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) break;
        }
        if (f == 1) break;
    }

    if (f == 1) {
        printf("%d %d %d\n", k + 1, j + 1, i + 1);
    } else {
        printf("-1\n");
    }

    return 0;
}
