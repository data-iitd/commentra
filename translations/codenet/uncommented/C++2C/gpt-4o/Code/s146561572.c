#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200010

void solve() {
    long long ans = 0;
    int n;
    scanf("%d", &n);
    
    // Contribution of The Nodes.
    for (int i = 1; i <= n; i++) {
        ans += i * 1LL * (n - i + 1);
    }
    
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
<<<<<<< HEAD
        int a = (u > v) ? u : v;
        int b = (u < v) ? u : v;
=======
        int a = u > v ? u : v;
        int b = u < v ? u : v;
>>>>>>> 98c87cb78a (data updated)
        ans -= b * 1LL * (n - a + 1);
    }
    
    printf("%lld\n", ans);
}

int main() {
    int t;
    // scanf("%d", &t);
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
