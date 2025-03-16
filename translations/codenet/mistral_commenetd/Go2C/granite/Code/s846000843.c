
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *aa = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }

    int *cumsum = (int *)malloc(sizeof(int) * (n + 1));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + aa[i];
    }

    int ans = 2020202020;
    for (int i = 1; i < n - 1; i++) {
        int diff1 = abs(cumsum[n] - cumsum[i]);
        int diff2 = cumsum[i] - cumsum[0];
        ans = ans < diff1? ans : diff1;
        ans = ans < diff2? ans : diff2;
    }

    printf("%d\n", ans);

    free(aa);
    free(cumsum);

    return 0;
}
