#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
    }

    if (sum % (n * (n + 1) / 2)) {
        printf("NO\n");
        return 0;
    }

    double k = (double)sum / (n * (n + 1) / 2);
    int b[2 * n];
    for (i = 0; i < n; i++) {
        b[i] = a[i];
        b[i + n] = a[i];
    }

    int flag = 1;
    for (i = 1; i < n; i++) {
        if ((b[i] + b[i - 1] - k) % n != 0 || (b[i] + b[i - 1] - k) / n < 0) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
