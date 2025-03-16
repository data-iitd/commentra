#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int count = 0;
    while (1) {
        if (a > 0 && b > 0) {
            count++;
            a--;
            b--;
        } else {
            break;
        }
    }
    int ans = a / 2 + b / 2;
    printf("%d %d\n", count, ans);
    return 0;
}
