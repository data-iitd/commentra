
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <random>
#include <complex>
#include <bitset>
#include <sys/time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it!= a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MAXN = 2e5 + 10;
const int LOGN = 20;

int n;
int a[MAXN];
int dl[MAXN];
int ans;
vector<pii> bans;

int mn[LOGN][MAXN];
int pw[MAXN];

void init() {
    REP(i, n) {
        if (a[i] > i) {
            printf("-1\n");
            exit(0);
        }
        dl[i] = i - a[i];
    }
    REP(i, n) {
        int r = i;
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        ans += a[r];
        i = r;
        bans.PB(MP(r - a[r], r));
    }
    pw[1] = 0;
    FOR(i, 2, MAXN) {
        pw[i] = pw[i / 2] + 1;
    }
    REP(i, n) {
        mn[0][i] = dl[i];
    }
    FOR(i, 1, LOGN) {
        REP(j, n) {
            if (j + (1 << (i - 1)) < n) {
                mn[i][j] = max(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            } else {
                mn[i][j] = mn[i - 1][j];
            }
        }
    }
}

int get(int l, int r) {
    r++;
    int p = pw[r - l];
    return max(mn[p][l], mn[p][r - (1 << p)]);
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &a[i]);
    }
    init();
    for (pii t: bans) {
        if (get(t.first, t.second) > t.second) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}

