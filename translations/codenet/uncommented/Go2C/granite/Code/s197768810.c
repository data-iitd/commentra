
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[m];
    int sum = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum > n) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", n - sum);
    return 0;
}
