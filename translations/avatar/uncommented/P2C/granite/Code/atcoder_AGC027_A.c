
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    qsort(a, n, sizeof(int));
    if (a[0] > x) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            x = 0;
            break;
        }
        x -= a[i];
        ans++;
    }
    if (x!= 0) {
        ans--;
    }
    printf("%d\n", ans);
    return 0;
}

