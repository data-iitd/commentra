
#include <stdio.h>

int main() {
    int t, s, q, ans = 0;
    scanf("%d %d %d", &t, &s, &q);
    while (s < t) {
        s *= q;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
// END-OF-CODE