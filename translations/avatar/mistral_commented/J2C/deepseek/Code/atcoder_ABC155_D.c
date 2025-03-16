#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007
#define INF 1000000000000000001

int DX[] = {-1, 0, 1, 0}, DY[] = {0, -1, 0, 1};

int n;
long long k;
long long *a;

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

int check(long long x) {
    long long tot = 0;

    for (int i = 0; i < n; i++) {
        long long now = a[i];
        int l = 0, r = n;

        if (now >= 0) {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] < x) l = c + 1;
                else r = c;
            }
            tot += l;
        } else {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] >= x) l = c + 1;
                else r = c;
            }
            tot += (n - l);
        }

        if (now * now < x) tot--;

        if (tot / 2 < k) return 1;
    }

    return 0;
}

int main() {
    scanf("%d %lld", &n, &k);
    a = (long long *)malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    qsort(a, n, sizeof(long long), compare);

    long long l = -INF, r = INF;

    while (l + 1 < r) {
        long long c = (l + r) / 2;
        if (check(c)) l = c;
        else r = c;
    }

    printf("%lld\n", l);

    free(a);
    return 0;
}

