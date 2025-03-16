#include <stdio.h>

int main() {
    int A, B, ans;
    scanf("%d %d", &A, &B);

    if (A >= 6 && A <= 12) {
        ans = B / 2;
    } else if (A > 12) {
        ans = B;
    }

    printf("%d\n", ans);

    return 0;
}

