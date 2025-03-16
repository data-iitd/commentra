
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;

int n;
int a[200000];
int b[200000];
ll sum[200001];

ll query(int x) {
    ll res = 0;
    for(; x > 0; x -= x & -x)
        res += sum[x];
    return res;
}

void update(int x, int v) {
    for(; x <= n; x += x & -x)
        sum[x] += v;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        ll tot = (ll)n * (n + 1) / 2;
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            int target = b[mid];
            ll cur = 0, cnt = 0;
            memset(sum, 0, sizeof(sum));
            for(int i = 0; i < n; i++) {
                cur += a[i] <= target? 1 : -1;
                update(cur + n, 1);
                cnt += query(cur + n);
            }
            if(cnt >= tot / 2 + 1)
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", b[l]);
    }
    return 0;
}

