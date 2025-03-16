
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *orig = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        orig[i] = i + 1;
    }
    int p[n], q[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    int pn = 0, qn = 0;
    for (int i = 0; i < n; i++) {
        if (orig[i] == p[0]) {
            pn = i;
        }
        if (orig[i] == q[0]) {
            qn = i;
        }
    }
    int ans = abs(pn - qn);
    printf("%d\n", ans);
    free(orig);
    return 0;
}
