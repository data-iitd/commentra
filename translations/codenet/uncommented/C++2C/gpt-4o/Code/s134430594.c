#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
#define LIM 20
#define N 200007

typedef struct {
    long long l;
    long long r;
    long long val;
} Ban;

long long mn[LIM][N];
long long pw[N];

void init(long long *a, int n) {
=======
#define int long long

struct Ban {
    int l;
    int r;
    int val;
};

#define LIM 20
#define N 200007

int mn[LIM][N];
int pw[N];

void init(int *a, int n) {
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        mn[0][i] = a[i];
    }
    for (int i = 0; i + 1 < LIM; i++) {
        for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
            mn[i + 1][j] = (mn[i][j] > mn[i][j + (1 << i)]) ? mn[i][j] : mn[i][j + (1 << i)];
        }
    }
    pw[1] = 0;
    for (int i = 2; i < N; i++) {
        pw[i] = pw[i / 2] + 1;
    }
}

<<<<<<< HEAD
long long get(int l, int r) {
=======
int get(int l, int r) {
>>>>>>> 98c87cb78a (data updated)
    r++;
    int p = pw[r - l];
    return (mn[p][l] < mn[p][r - (1 << p)]) ? mn[p][l] : mn[p][r - (1 << p)];
}

int main() {
<<<<<<< HEAD
    long long n;
    scanf("%lld", &n);
    long long *a = (long long *)malloc(n * sizeof(long long));
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    long long *dl = (long long *)malloc(n * sizeof(long long));
    for (long long i = 0; i < n; i++) {
=======
    int n;
    scanf("%lld", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    int *dl = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
>>>>>>> 98c87cb78a (data updated)
        if (a[i] > i) {
            printf("-1\n");
            free(a);
            free(dl);
            return 0;
        }
        dl[i] = i - a[i];
    }

<<<<<<< HEAD
    long long ans = 0;
    Ban *bans = (Ban *)malloc(n * sizeof(Ban));
    long long ban_count = 0;

    for (long long i = 0; i < n; i++) {
        long long r = i;
=======
    int ans = 0;
    struct Ban *bans = (struct Ban *)malloc(n * sizeof(struct Ban));
    int ban_count = 0;

    for (int i = 0; i < n; i++) {
        int r = i;
>>>>>>> 98c87cb78a (data updated)
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        ans += a[r];
        i = r;
<<<<<<< HEAD
        bans[ban_count++] = (Ban){r - a[r], r, r - a[r]};
    }

    init(dl, n);
    for (long long i = 0; i < ban_count; i++) {
        Ban t = bans[i];
=======
        bans[ban_count++] = (struct Ban){r - a[r], r, r - a[r]};
    }

    init(dl, n);
    for (int i = 0; i < ban_count; i++) {
        struct Ban t = bans[i];
>>>>>>> 98c87cb78a (data updated)
        if (get(t.l, t.r) > t.val) {
            printf("-1\n");
            free(a);
            free(dl);
            free(bans);
            return 0;
        }
    }
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    printf("%lld\n", ans);
    
    free(a);
    free(dl);
    free(bans);
    return 0;
<<<<<<< HEAD
} 
=======
}

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
