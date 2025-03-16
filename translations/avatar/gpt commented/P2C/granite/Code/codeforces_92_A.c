
#include <stdio.h>

int main() {
    int n, m, i = 1;
    scanf("%d %d", &n, &m);
    while (m >= i) {
        m -= i;
        i = (i % n) + 1;
    }
    printf("%d\n", m);
    return 0;
}
// END-OF-CODE