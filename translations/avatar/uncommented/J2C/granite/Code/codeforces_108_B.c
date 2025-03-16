
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int));
    for (i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i] * 2 && a[i]!= a[i + 1]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
// END-OF-CODE