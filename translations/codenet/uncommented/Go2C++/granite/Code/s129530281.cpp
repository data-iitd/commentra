
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <iomanip>
#include <cctype>
#include <random>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pipii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define endl '\n'
#define all(v) (v.begin(), v.end())
#define rall(v) (v.rbegin(), v.rend())
#define sz(x) (int)x.size()
#define debug(x) cerr << #x << " " << x << endl;
#define debug2(x, y) cerr << #x << " " << x << " " << #y << " " << y << endl;
#define unsyncIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;

struct Segment {
    int n, h, i, chunk;
    vector<int> unit, bucket[10];

    void init(int n) {
        this->n = n;
        unit.resize(1);
        unit[0] = 1;
        bucket[0].resize(n);

        chunk = 8;
        for (int i = 0; n > 1; i++) {
            n = (n - 1) / chunk + 1;
            bucket[i].resize(n);
            unit.resize(i + 1);
            unit[i + 1] = unit[i] * chunk;
        }
        h = unit.size();
    }

    void maximize(int index, int value) {
        bucket[0][index] = value;
        for (i = 0; i < h - 1; i++) {
            int s = index - index % chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            int parent = index / chunk;
            int max = 0;
            for (int j = s; j < t; j++) {
                if (max < bucket[i][j]) {
                    max = bucket[i][j];
                }
            }
            bucket[i + 1][parent] = max;
            index /= chunk;
        }
    }

    int top() {
        int index = 0;
        for (i = h - 2; i >= 0; i--) {
            int s = index * chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            for (int j = s; j < t; j++) {
                if (bucket[i][j] == bucket[i + 1][index]) {
                    index = j;
                    break;
                }
            }
        }

        return index;
    }
};

int main() {
    unsyncIO;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    Segment seg;
    seg.init(n);
    for (int i = 0; i < n; i++) {
        cin >> seg.bucket[0][i];
    }
    for (int i = 0; i < m; i++) {
        seg.maximize(seg.top(), seg.bucket[0][seg.top()] / 2);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    cout << ans << endl;

    return 0;
}

// END-OF-CODE