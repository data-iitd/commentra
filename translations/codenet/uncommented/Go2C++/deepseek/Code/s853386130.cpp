#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
const int INF = 1000000007;

// Union-Find
class UnionFind {
public:
    vector<int> d;
    UnionFind(int n) : d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return -d[find(x)];
    }
};

// mod
int modpow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int modinv(int n, int mod) {
    return modpow(n, mod - 2, mod);
}

int modcomb(int n, int a, int mod) {
    int x = 1, y = 1;
    for (int i = 0; i < a; i++) {
        x = x * (n - i) % mod;
        y = y * (i + 1) % mod;
    }
    return x * modpow(y, mod - 2, mod) % mod;
}

int modfactorial(int n, int mod) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i % mod;
    }
    return res;
}

// Combination
class Combination {
public:
    vector<int> facts, invs;
    int mod;
    Combination(int n, int mod) : facts(n + 1), invs(n + 1), mod(mod) {
        facts[0] = 1;
        for (int i = 1; i <= n; i++) {
            facts[i] = facts[i - 1] * i % mod;
        }
        invs[n] = modinv(facts[n], mod);
        for (int i = n - 1; i >= 0; i--) {
            invs[i] = invs[i + 1] * (i + 1) % mod;
        }
    }
    int calc(int n, int k) {
        int ret = facts[n] * invs[k];
        ret %= mod;
        ret = ret * invs[n - k] % mod;
        return ret;
    }
};

// Utility
int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

map<int, int> primeFactor(int x) {
    map<int, int> res;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            res[i]++;
            x /= i;
        }
    }
    if (x != 1) {
        res[x] = 1;
    }
    return res;
}

vector<int> divisor(int x) {
    vector<int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i != x / i) {
                res.push_back(x / i);
            }
        }
    }
    return res;
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int pow(int a, int n) {
    int ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= a;
    }
    return ret;
}

// Queue
class Queue {
public:
    vector<int> data;
    void push(int x) {
        data.push_back(x);
    }
    bool empty() {
        return data.empty();
    }
    int pop() {
        int x = data.front();
        data.erase(data.begin());
        return x;
    }
};

// Stack
class Stack {
public:
    vector<int> data;
    void push(int x) {
        data.push_back(x);
    }
    bool empty() {
        return data.empty();
    }
    int pop() {
        int x = data.back();
        data.pop_back();
        return x;
    }
};

// priority_queue
class PriorityQueue {
public:
    priority_queue<int> data;
    void push(int x) {
        data.push(x);
    }
    bool empty() {
        return data.empty();
    }
    int pop() {
        int x = data.top();
        data.pop();
        return x;
    }
};

// sortable points
struct Point {
    int x, y;
};

bool operator<(const Point &a, const Point &b) {
    return a.x < b.x;
}

typedef vector<Point> Points;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, R;
    cin >> n >> m >> R;

    vector<int> rs(R);
    for (int i = 0; i < R; i++) {
        cin >> rs[i];
        rs[i]--;
    }

    vector<vector<int>> costs(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        costs[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // ワーシャルフロイド法で最短経路を算出
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    // 順列で訪問先の順序をすべて試す
    // これでは重複して訪問する町がでてしまうか。。
    sort(rs.begin(), rs.end());
    int ans = INF;
    do {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            int from = rs[j - 1];
            int to = rs[j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
    } while (next_permutation(rs.begin(), rs.end()));

    cout << ans << endl;

    return 0;
}
