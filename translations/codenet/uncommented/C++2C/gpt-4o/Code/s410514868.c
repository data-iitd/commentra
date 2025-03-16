#include <stdio.h>
#include <string.h>

typedef long long ll;

int main(void) {
    ll n, k, ans = 0, ans2 = 0, cnt = 0;
    char s[100001]; // Assuming the maximum length of the string is 100000

    scanf("%lld %lld", &n, &k);
    scanf("%s", s);

    char L = s[0];
    for (int i = 1; i < n; i++) {
        if (L == s[i]) {
            cnt++;
        } else {
            L = s[i];
            ans += cnt;
            ans2++;
            cnt = 0;
        }
    }
    ans += cnt;
    ans2++;
<<<<<<< HEAD

    printf("%lld\n", ans + (2 * k < ans2 - 1 ? 2 * k : ans2 - 1));
=======
    
    printf("%lld\n", ans + (2 * k < ans2 - 1 ? 2 * k : ans2 - 1));
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
