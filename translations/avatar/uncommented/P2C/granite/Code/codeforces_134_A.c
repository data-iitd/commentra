
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        x += w[i];
    }
    int d[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((x - w[i]) / (n - 1) == w[i]) {
            d[count] = i + 1;
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", d[i]);
    }
    return 0;
}
