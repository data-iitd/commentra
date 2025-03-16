#include <stdio.h>
<<<<<<< HEAD
#include <string.h>

#define REP(i,n) for(int i=0;i<(n);++i)
#define INF 1000000000
#define MOD 1000000007
=======
#include <stdlib.h>

#define REP(i,n) for(int i=0;i<(n);++i)
#define INF 1e9
#define MOD 1000000007

>>>>>>> 98c87cb78a (data updated)
typedef long long llong;

int main() {
    int n;
    scanf("%d", &n);
<<<<<<< HEAD
    int cnt[26] = {0}; // Initialize count array to 0
    char s[n];

    REP(i, n) {
        scanf(" %c", &s[i]); // Read character with space to skip whitespace
=======
    
    int cnt[26] = {1}; // Initialize the first element to 1
    char *s = (char *)malloc(n * sizeof(char));
    
    REP(i, n) {
        scanf(" %c", &s[i]); // Note the space before %c to consume any whitespace
>>>>>>> 98c87cb78a (data updated)
        cnt[s[i] - 'a']++;
    }

    llong ans = cnt[0];
    for(int i = 1; i < 26; ++i) {
        ans *= cnt[i];
        ans %= MOD;
    }

    printf("%lld\n", ans - 1);
<<<<<<< HEAD
=======
    
    free(s); // Free the allocated memory
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
