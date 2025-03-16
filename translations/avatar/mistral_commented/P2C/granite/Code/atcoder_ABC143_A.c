
#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    int ans = A - 2 * B;
    if (ans < 0) {
        ans = 0;
    }
    printf("%d\n", ans);
    return 0;
}
// END-OF-CODE