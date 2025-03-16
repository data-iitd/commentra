
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k, t, f = 0;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (k = 0; k < n; k++) {
        t = a[k];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                if (i!= j && t == (a[i] + a[j])) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) break;
        }
        if (f == 1) break;
    }
    if (f == 1) printf("%d %d %d\n", k + 1, i + 1, j + 1);
    else printf("-1\n");
    return 0;
}
//END-OF-CODE