#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int i = 1;
    while (m >= i) {
        m -= i;
        i = (i % n) + 1;
    }
    printf("%d\n", m);
    return 0;
}
