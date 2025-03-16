#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int w[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    int d[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((sum - w[i]) * 1.0 / (n - 1) == w[i]) {
            d[count++] = i + 1;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}
