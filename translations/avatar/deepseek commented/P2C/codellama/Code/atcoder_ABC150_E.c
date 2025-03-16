
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, mod, i, j, c[100000], b, a, ans;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    mod = 1000000007;
    b = pow(2, 2 * n - 2, mod);
    a = 2 * b % mod;
    ans = 0;
    for (i = 0; i < n; i++)
    {
        ans += c[i] * (a + i * b);
        ans %= mod;
    }
    printf("%d", ans);
    return 0;
}
