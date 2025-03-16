#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007LL

<<<<<<< HEAD
long long int INF = 1001001001001001LL;
=======
long long int min(long long int a, long long int b) {
    return a < b ? a : b;
}

long long int max(long long int a, long long int b) {
    return a > b ? a : b;
}
>>>>>>> 98c87cb78a (data updated)

int main() {
    int n;
    scanf("%d", &n);
    
    long long int *a = (long long int *)malloc(n * sizeof(long long int));
    long long int *acc = (long long int *)malloc((n + 1) * sizeof(long long int));
    
    acc[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        acc[i + 1] = (acc[i] + a[i]) % MOD;
    }

    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (a[i] % MOD) * ((MOD + acc[n] - acc[i + 1]) % MOD)) % MOD) % MOD;
    }
    
    printf("%lld\n", ans);
    
    free(a);
    free(acc);
    
    return 0;
}

<<<<<<< HEAD
// <END-OF-CODE>
=======
/* <END-OF-CODE> */
>>>>>>> 98c87cb78a (data updated)
