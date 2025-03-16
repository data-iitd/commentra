#include <stdio.h>

#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
<<<<<<< HEAD
    int n, a, b;
    scanf("%d", &n);
    long long cnt[10][10] = {0}; // Initialize the array to zero

=======
    int n, ii, a, b;
    scanf("%d", &n);
    long long cnt[10][10] = {0}; // Initialize the array to zero

    REP(i, 100) {
        cnt[i % 10][i / 10] = 0; // This line is redundant since we initialized cnt to zero
    }

>>>>>>> 98c87cb78a (data updated)
    for (int i = 1; i <= n; i++) {
        b = i % 10;
        a = i;
        while (a >= 10) {
            a /= 10;
        }
        cnt[a][b]++;
    }

    long long ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
