
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int p[n];
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        if (p[i] > p[i+1] && p[i+1] > p[i+2]) ans++;
        if (p[i] < p[i+1] && p[i+1] < p[i+2]) ans++;
    }

    printf("%d\n", ans);
    return 0;
}

