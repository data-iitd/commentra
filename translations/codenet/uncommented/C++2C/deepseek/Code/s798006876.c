#include <stdio.h>

#define MAX_N 1000

int data[MAX_N];

int main() {
    int m, nmi, nma;
    while (scanf("%d %d %d", &m, &nmi, &nma) == 3 && nmi != 0) {
        for (int i = 0; i < m; i++) scanf("%d", &data[i]);
        int ma = 0;
        int ans = 0;
        for (int i = nmi - 1; i < nma; i++) {
            if (ma <= data[i] - data[i + 1]) {
                ans = i + 1;
                ma = data[i] - data[i + 1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
