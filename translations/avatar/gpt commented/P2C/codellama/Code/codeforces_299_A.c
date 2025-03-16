#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n, i, j, k, a[100000], b[100000], c[100000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        b[i] = a[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
    if (a[0] % b[0] == 0) {
        printf("%d", a[0]);
    } else {
        printf("-1");
    }
    return 0;
}

