#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

#define DEBUG(var) cerr << #var << ": " << (var) << " "
#define DEBUG_EN(var) cerr << #var << ": " << (var) << endl

using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = VV<V<T>>;
template<class T, class S> using P = pair<T, S>;

constexpr int MOD = 1000000000 + 7;
constexpr int INF_INT = 1 << 30;
constexpr ll INF_LL = 1LL << 60;
constexpr int WHITE = 0;
constexpr int GRAY = 1;
constexpr int BLACK = 2;

#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR3(i, m, n) for (int i = (m); i < (int)(n); i++)
#define FOR_R(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOR3_R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); i--)
#define all(x) x.begin(), x.end()

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &vec) {
    os << "{";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "}";
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec) {
    os << "{";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "}";
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec) {
    os << "{";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "}";
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
    os << "{";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "}";
    return os;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
    os << "(" << pa.first << "," << pa.second << ")";
    return os;
}

template<typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
    os << "{";
    for (const auto &p : mp) {
        os << p.first << "=>" << p.second << ",";
    }
    os << "}";
    return os;
}

template<typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) {
    os << "{";
    for (const auto &p : mp) {
        os << p.first << "=>" << p.second << ",";
    }
    os << "}";
    return os;
}

template<typename T>
void print(const T &x) {
    cout << x << "\n";
}

template<typename T, typename... Args>
void print(const T &first, const Args... args) {
    cout << first << " ";
    print(args...);
}

template<typename T>
void printList(const T &lst, const string sep = " ", const string end = "\n") {
    for (size_t i = 0; i < lst.size(); ++i) {
        if (i > 0) cout << sep;
        cout << lst[i];
    }
    cout << end;
}

template<typename T>
void add(T &a, const T &b) {
    a += b;
}

template<typename T>
void sub(T &a, const T &b) {
    a -= b;
}

template<typename T>
void mul(T &a, const T &b) {
    a *= b;
}

template<typename T>
void div(T &a, const T &b) {
    a /= b;
}

template<typename T>
T add_mod(const T &a, const T &b, const T &mod) {
    return (a + b) % mod;
}

template<typename T>
T sub_mod(const T &a, const T &b, const T &mod) {
    return (a - b + mod) % mod;
}

template<typename T>
T mul_mod(const T &a, const T &b, const T &mod) {
    return (a * b) % mod;
}

template<typename T>
T div_mod(const T &a, const T &b, const T &mod) {
    return (a * mod_pow(b, mod - 2, mod)) % mod;
}

template<typename T>
T mod_pow(T base, T exp, const T &mod) {
    T res = 1;
    T pow = base;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * pow) % mod;
        }
        pow = (pow * pow) % mod;
        exp /= 2;
    }
    return res;
}

template<typename T>
struct ReRootingSolver {
    int nodeCount;
    VV<int> adjacents;
    VV<int> indexForAdjacents;
    V<T> res;
    VV<T> dp;
    T identity;
    function<T(T, T)> operate;
    function<T(T, int)> operateNode;

    ReRootingSolver(int nodeCount, const VV<P<int, int>> &edges, T identity, function<T(T, T)> operate, function<T(T, int)> operateNode)
            : nodeCount(nodeCount), identity(identity), operate(operate), operateNode(operateNode) {
        adjacents.resize(nodeCount);
        indexForAdjacents.resize(nodeCount);
        for (const auto &e : edges) {
            indexForAdjacents[e[0].first].push_back(adjacents[e[1].first].size());
            indexForAdjacents[e[1].first].push_back(adjacents[e[0].first].size());
            adjacents[e[0].first].push_back(e[1].first);
            adjacents[e[1].first].push_back(e[0].first);
        }
        dp.resize(adjacents.size());
        for (int i = 0; i < adjacents.size(); i++) {
            dp[i].resize(adjacents[i].size());
        }
        res.resize(adjacents.size());
        if (nodeCount > 1) {
            initialize();
        } else {
            res[0] = operateNode(identity, 0);
        }
    }

    void initialize() {
        V<int> parents(nodeCount), order(nodeCount);
        int index = 0;
        stack<int> stack;
        stack.push(0);
        parents[0] = -1;
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            order[index] = node;
            index++;
            for (int adjacent : adjacents[node]) {
                if (adjacent == parents[node]) continue;
                stack.push(adjacent);
                parents[adjacent] = node;
            }
        }
        for (int i = order.size() - 1; i >= 1; i--) {
            int node = order[i];
            int parent = parents[node];
            T accum = identity;
            int parentIndex = -1;
            for (int j = 0; j < adjacents[node].size(); j++) {
                if (adjacents[node][j] == parent) {
                    parentIndex = j;
                    continue;
                }
                accum = operate(accum, dp[node][j]);
            }
            dp[parent][indexForAdjacents[node][parentIndex]] = operateNode(accum, node);
        }
        for (int i = 0; i < order.size(); i++) {
            int node = order[i];
            T accum = identity;
            vector<T> accumsFromTail(adjacents[node].size());
            accumsFromTail[accumsFromTail.size() - 1] = identity;
            for (int j = accumsFromTail.size() - 1; j >= 1; j--) {
                accumsFromTail[j - 1] = operate(dp[node][j], accumsFromTail[j]);
            }
            for (int j = 0; j < accumsFromTail.size(); j++) {
                dp[adjacents[node][j]][indexForAdjacents[node][j]] = operateNode(operate(accum, accumsFromTail[j]), node);
                accum = operate(accum, dp[node][j]);
            }
            res[node] = operateNode(accum, node);
        }
    }

    T query(int node) {
        return res[node];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    VV<P<int, int>> edges(n - 1);
    FOR(i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[i] = {{x, y}, {y, x}};
    }

    auto f = [m](int x, int y) { return (x * y) % m; };
    auto g = [](int v, int p) { return v + 1; };

    ReRootingSolver<int> s(n, edges, 1, f, g);
    FOR(i, n) {
        cout << s.query(i) - 1 << "\n";
    }

    return 0;
}
