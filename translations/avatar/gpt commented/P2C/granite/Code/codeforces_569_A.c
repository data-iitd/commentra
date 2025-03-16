
#include <stdio.h>

int main() {
    int t, s, q;
    scanf("%d %d %d", &t, &s, &q);
    int ans = 0;
    while (s < t) {
        s *= q;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
// END-OF-CODE