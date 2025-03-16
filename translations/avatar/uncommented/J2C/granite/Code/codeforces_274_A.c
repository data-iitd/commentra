
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <stdarg.h>
#include <utils.h>
#include <vector>
#include <set>

int main(int argc, char *argv[]) {
    int n, k;
    scanf("%d%d", &n, &k);
    std::set<long long> s;
    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    std::sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % k!= 0 ||!s.count(a[i] / k)) {
            ans++;
            s.insert(a[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
// END-OF-CODE