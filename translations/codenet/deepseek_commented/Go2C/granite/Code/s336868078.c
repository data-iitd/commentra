

#include <stdio.h>

int solve(int a, int b, int c) {
    int temp_;
    if (c == a + b) {
        temp_ = b + c;
    } else if (c - 1 > a + b) {
        int temp = (c - 1) - (a + b);
        temp_ = b + c - temp;
    } else {
        temp_ = b + c;
    }
    return temp_;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int ans = solve(a, b, c);
    printf("%d\n", ans);
    return 0;
}

