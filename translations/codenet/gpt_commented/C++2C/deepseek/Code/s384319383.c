#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(v) (v), (v) + (sizeof(v) / sizeof(*(v)))
#define INF 1e9
#define MOD 1000000007

typedef long long llong;

int main() {
    int n;
    scanf("%d", &n);

    int cnt[26] = {1};
    char s[n + 1];

    scanf("%s", s);

    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
    }

    llong ans = cnt[0];

    for (int i = 1; i < 26; ++i) {
        ans *= cnt[i];
        ans %= MOD;
    }

    printf("%lld\n", ans - 1);
    return 0;
}
