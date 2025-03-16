#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int ans = 0;
    if (6 <= A && A <= 12) {
        ans = B / 2;
    } else if (A > 12) {
        ans = B;
    }
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
