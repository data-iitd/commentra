
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int *l = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    for (i = 0; i < n; i++) {
        if (l[i] + 1 < n && l[i] + 2 < n && l[i] + 1 == l[i + 1] && l[i] + 2 == l[i + 2]) {
            printf("YES\n");
            break;
        }
    }
    if (i == n) {
        printf("NO\n");
    }
    free(l);
    return 0;
}
