#include <stdio.h>

int main(void) {
    int n, m;

    scanf("%d %d", &n, &m);

    // n gu m ki
    int ans = 0;
    
    // gu gu
    ans += n * (n - 1) / 2;

    // kiki
    ans += m * (m - 1) / 2;

    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
