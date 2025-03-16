
#include <stdio.h>

int main() {
    int n, i;
    long long cnt[21] = {0}, res = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x + 10]++;
    }
    for (i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2;
    printf("%lld\n", res);
    return 0;
}
//END-OF-CODE