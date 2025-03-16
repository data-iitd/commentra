#include <stdio.h>

typedef long long ll;

int main()
{
    ll n, k; 
    scanf("%lld %lld", &n, &k);
    ll MOD = 1e9 + 7;
    ll mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
    ll mn = k * (k - 1) / 2;
    ll res = 0;

    for (int i = k; i <= n + 1; ++i)
    {
        res += mx - mn + 1;
        mx += n - i;
        mn += i;
        res %= MOD;
    }
    
    printf("%lld\n", res);
    return 0;
}

// <END-OF-CODE>
