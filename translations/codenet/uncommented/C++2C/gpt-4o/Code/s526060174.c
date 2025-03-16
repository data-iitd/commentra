#include <stdio.h>

#define rep(S, L) for (int i = S; i < L; ++i)

int main() {
    int n, m;
    int k, a;
<<<<<<< HEAD
    int x[32] = {0}; // Array size is 32 to accommodate indices 1 to 31
    scanf("%d %d", &n, &m);
=======
    int x[31] = {0}; // Initialize the array to zero
    scanf("%d %d", &n, &m);
    
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a);
            x[a]++;
        }
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (x[i] == n) {
            ans++;
        }
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
