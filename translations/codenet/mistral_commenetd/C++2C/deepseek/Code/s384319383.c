#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(v) (v), (v) + sizeof(v) / sizeof(*v)
#define INF 1e9
#define MOD 1e9 + 7

typedef long long llong;

int main() {
    int n;
    scanf("%d", &n);

    int cnt[26] = {1};
    char s[n];

    REP(i, n) {
        scanf(" %c", &s[i]);
        cnt[s[i] - 'a']++;
    }

    llong ans = 1;
    for (int i = 0; i < 26; ++i) {
        ans *= cnt[i];
    }

    ans--;

    printf("%lld\n", ans);

    return 0;
}
