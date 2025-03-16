#include <stdio.h>
#include <stdlib.h>

#define MOD (1000000007)
#define INF (1000000000000000000LL + 1)

long long a[100000]; // Assuming a maximum size of 100000 for the array
int n;
long long k;

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
    }
    return (tot / 2 < k);
}

int main() {
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; ++i) {
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
    return 0;
}

// <END-OF-CODE>
