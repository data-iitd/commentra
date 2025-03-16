#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int bb[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &bb[i]);
    }
    int aa[n];
    int m = 0;
    for (int a = n - 1; a >= 0; a--) {
        int j = 0;
        while (bb[a] > 0) {
            if (aa[j] >= a + k) {
                bb[a]--;
            }
            j++;
        }
        for (int j_ = m++; j_ > j; j_--) {
            aa[j_] = aa[j_ - 1];
        }
        aa[j] = a;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", aa[i] + 1);
    }
    printf("\n");
    return 0;
}

