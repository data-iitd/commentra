
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int b[n];
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        res += abs(b[i] - b[i - 1]);
    }

    printf("%d\n", res);

    return 0;
}
