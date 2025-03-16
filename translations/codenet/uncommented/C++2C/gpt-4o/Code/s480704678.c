#include <stdio.h>
<<<<<<< HEAD

#define MOD 1000000007LL

=======
#include <stdlib.h>

#define MOD 1000000007LL

typedef long long int lint;

>>>>>>> 98c87cb78a (data updated)
int main() {
    int n;
    scanf("%d", &n);
    
<<<<<<< HEAD
    long long int a[n];
    long long int acc[n + 1];
=======
    lint *a = (lint *)malloc(n * sizeof(lint));
    lint *acc = (lint *)malloc((n + 1) * sizeof(lint));
>>>>>>> 98c87cb78a (data updated)
    acc[0] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        acc[i + 1] = (acc[i] + a[i]) % MOD;
    }

<<<<<<< HEAD
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (a[i] % MOD) * ((MOD + acc[n] - acc[i + 1]) % MOD)) % MOD) % MOD;
    }
    
    printf("%lld\n", ans);
=======
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (a[i] % MOD) * ((MOD + acc[n] - acc[i + 1]) % MOD)) % MOD) % MOD;
    }

    printf("%lld\n", ans);

    free(a);
    free(acc);
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
