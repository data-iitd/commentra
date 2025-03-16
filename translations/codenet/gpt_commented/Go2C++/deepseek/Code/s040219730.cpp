#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <cstring>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i, n, m) for(int i = (n); i <= (m); i++)
#define FORR(i, n, m) for(int i = (m); i >= (n); i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define ALL(v) (v).begin(), (v).end()
#define INF (int)1e9
#define LLINF (long long)1e18
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<P> VP;
template<class T> bool CHMAX(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool CHMIN(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

const int MOD = 1e9 + 7;
const int MAX = 500005;

int n, q;
VI C;
vector<tuple<int, int, int>> Q;
int P[MAX];
int Answers[MAX];

struct FenwickTree {
    vector<int> dat;
    int n;
    int minPow2;

    FenwickTree(int n) {
        dat.resize(n + 1, 0);
        this->n = n;
        minPow2 = 1;
        while ((minPow2 << 1) <= n) {
            minPow2 <<= 1;
        }
    }

    void add(int i, int x) {
        while (i <= n) {
            dat[i] += x;
            i += i & -i;
        }
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += dat[i];
            i -= i & -i;
        }
        return s;
    }

    int lowerBound(int w) {
        if (w <= 0) return 0;
        int x = 0;
        for (int k = minPow2; k > 0; k /= 2) {
            if (x + k <= n && dat[x + k] < w) {
                w -= dat[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};

int main() {
    cin >> n >> q;
    C.resize(n);
    REP(i, n) cin >> C[i];
    REP(i, q) {
        int l, r;
        cin >> l >> r;
        Q.emplace_back(l, r, i);
    }
    sort(ALL(Q), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<1>(a) < get<1>(b);
    });

    FenwickTree ft(MAX);
    int k = 0;
    REP(i, q) {
        int l = get<0>(Q[i]);
        int r = get<1>(Q[i]);
        int idx = get<2>(Q[i]);
        while (k < r) {
            if (P[C[k]] != -1) {
                ft.add(P[C[k]] + 1, -1);
            }
            P[C[k]] = k;
            ft.add(k + 1, 1);
            k++;
        }
        Answers[idx] = ft.sum(r) - ft.sum(l - 1);
    }

    REP(i, q) {
        cout << Answers[i] << endl;
    }

    return 0;
}
