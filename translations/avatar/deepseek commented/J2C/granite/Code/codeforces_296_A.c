
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[1001] = {0};
    int i;
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int max = 0;
    for (i = 1; i <= 1000; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    if (n % 2 == 0) {
        if (max <= n / 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        if (max <= n / 2 + 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
