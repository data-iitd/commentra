

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < 2 * a[i] && a[i]!= a[i + 1]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
