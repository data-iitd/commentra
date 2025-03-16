
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, l, r, sAll, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk);

    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = l;
    }

    sAll -= sk + (n - k) * l;
    sk -= k * l;

    int idx = n - 1;
    while (sk > 0 && idx >= n - k) {
        ans[idx--]++;
        sk--;
    }

    while (sAll > 0) {
        idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++;
            sAll--;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    printf("\n");
    return 0;
}

