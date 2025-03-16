#include <stdio.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    int tmpSum = 0;
    int rs = 0;
    for (int i = 0; i < n; i++) {
        tmpSum += l[i];
        if (tmpSum <= x) {
            rs = i + 2;
        } else {
            break;
        }
    }
    printf("%d\n", rs);
    return 0;
}
