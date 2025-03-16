#include <stdio.h>

int solve(int a, int b, int c) {
    int temp;
    if (c == a + b) {
        temp = b + c;
    } else if (c - 1 > a + b) {
        temp = (c - 1) - (a + b);
        temp = b + c - temp;
    } else {
        temp = b + c;
    }
    return temp;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int ans = solve(a, b, c);
    printf("%d\n", ans);

    return 0;
}
