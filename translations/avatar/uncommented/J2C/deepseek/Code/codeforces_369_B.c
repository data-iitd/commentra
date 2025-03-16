#include <stdio.h>
#include <stdlib.h>

int* getPoints(int n, int k, int l, int r, int sAll, int sk) {
    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = l;
    }
    sAll -= sk + (n - k) * l;
    sk -= k * l;
    while (sk > 0) {
        int idx = n - 1;
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++;
            sk--;
        }
    }
    while (sAll > 0) {
        int idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++;
            sAll--;
        }
    }
    return ans;
}

int main() {
    int n, k, l, r, sAll, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk);
    int* ans = getPoints(n, k, l, r, sAll, sk);
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    free(ans);
    return 0;
}

