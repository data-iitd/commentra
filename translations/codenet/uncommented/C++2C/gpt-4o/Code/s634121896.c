#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAXN 1000000

<<<<<<< HEAD
long long dp[MAXN + 1];
int kek[MAXN + 1];
int prev[MAXN + 1];

void solve() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    memset(kek, 0, sizeof(kek));
    memset(prev, -1, sizeof(prev));

=======
void solve() {
    int n;
    scanf("%lld", &n);
    long long nums[n];
    long long dp[n + 1];
    dp[0] = 1;
    
    // Initialize maps
    long long kek[MAXN] = {0};
    long long prev[MAXN] = {0};
    
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }
    
>>>>>>> 98c87cb78a (data updated)
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + (prev[nums[i - 1]] != i - 1 ? kek[nums[i - 1]] : 0);
        dp[i] %= MOD;
        kek[nums[i - 1]] = dp[i];
        prev[nums[i - 1]] = i;
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    printf("%lld\n", dp[n]);
}

int main() {
<<<<<<< HEAD
=======
    // Fast I/O is not necessary in C for this problem
>>>>>>> 98c87cb78a (data updated)
    solve();
    return 0;
}

// <END-OF-CODE>
