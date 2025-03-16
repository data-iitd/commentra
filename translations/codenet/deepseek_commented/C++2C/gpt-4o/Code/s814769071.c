#include <stdio.h>

typedef long long ll;

int main()
{
    // Step 2: Read input values
    ll n, k; 
    scanf("%lld %lld", &n, &k);
<<<<<<< HEAD
    ll MOD = 1e9 + 7;
=======
    ll MOD = 1000000007;
>>>>>>> 98c87cb78a (data updated)

    // Step 3: Calculate the maximum and minimum sums
    ll mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
    ll mn = k * (k - 1) / 2;

    // Step 4: Initialize variables
    ll res = 0;

    // Step 5: Loop through possible lengths
    for (int i = k; i <= n + 1; ++i)
    {
        // Update res, mx, and mn in each iteration
        res += mx - mn + 1;
        mx += n - i;
        mn += i;
        res %= MOD;
    }

    // Step 6: Output the result
    printf("%lld\n", res);
    
    return 0;
}

// <END-OF-CODE>
