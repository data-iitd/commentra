#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int r;
    while ((r = a % b) > 0) {
        a = b;
        b = r;
    }
    return b;
}

int main() {
    int n;
    scanf("%d", &n);

    int ans;
    scanf("%d", &ans);

    for (int i = 1; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ans = gcd(ans, a);
    }

    printf("%d\n", ans);

    return 0;
}
