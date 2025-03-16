#include <stdio.h>

int reverse(int n) {
    if (n < 10) return n * 10;
    int t = n, r = 0;
    while (t > 0) {
        r = (r * 10) + (t % 10);
        t = t / 10;
    }
    return r;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int t = reverse(m);
    printf("%d\n", t + n);
    return 0;
}

// <END-OF-CODE>
