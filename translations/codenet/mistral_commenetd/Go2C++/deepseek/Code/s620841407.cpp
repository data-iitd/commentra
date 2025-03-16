#include <bits/stdc++.h>
using namespace std;

// I/O
string ReadString() {
    string s;
    cin >> s;
    return s;
}

int ReadInt() {
    int i;
    cin >> i;
    return i;
}

vector<int> ReadIntSlice(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

vector<string> ReadRuneSlice(int n) {
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

double ReadFloat64() {
    double d;
    cin >> d;
    return d;
}

vector<double> ReadFloat64Slice(int n) {
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Utility
string ZeroPaddingRuneSlice(int num, int length) {
    string s = to_string(num);
    if (length - (int)s.size() > 0) {
        s = string(length - (int)s.size(), '0') + s;
    }
    return s;
}

template <class T>
void PrintIntsLine(T... args) {
    ((cout << args << " "), ...);
    cout << "\n";
}

// Constants
constexpr int MOD = 1000000000 + 7;
constexpr int ALPHABET_NUM = 26;
constexpr long long INF_INT64 = 1LL << 60;
constexpr int INF_BIT60 = 1 << 60;
constexpr int INF_INT32 = 1 << 30;
constexpr int INF_BIT30 = 1 << 30;
constexpr int NIL = -1;

// for dijkstra, prim, and so on
constexpr int WHITE = 0;
constexpr int GRAY = 1;
constexpr int BLACK = 2;

// ReRootingSolver
using T = int;

struct ReRootingSolver {
    int NodeCount;
    vector<vector<int>> Adjacents;
    vector<vector<int>> IndexForAdjacents;
    vector<T> Res;
    vector<vector<T>> DP;
    T Identity;
    function<T(T, T)> Operate;
    function<T(T, int)> OperateNode;

    ReRootingSolver(
        int nodeCount, vector<vector<int>>& edges, T identity, function<T(T, T)> operate, function<T(T, int)> operateNode)
        : NodeCount(nodeCount), Identity(identity), Operate(operate), OperateNode(operateNode) {
        Adjacents.resize(nodeCount);
        IndexForAdjacents.resize(nodeCount);
        for (auto& e : edges) {
            IndexForAdjacents[e[0]].push_back(Adjacents[e[1]].size());
            IndexForAdjacents[e[1]].push_back(Adjacents[e[0]].size());
            Adjacents[e[0]].push_back(e[1]);
            Adjacents[e[1]].push_back(e[0]);
        }

        DP.resize(Adjacents.size());
        Res.resize(Adjacents.size());
        for (auto& dp : DP) {
            dp.resize(Adjacents[0].size());
        }

        if (NodeCount > 1) {
            Initialize();
        } else {
            Res[0] = OperateNode(Identity, 0);
        }
    }

    T Query(int node) {
        return Res[node];
    }

    void Initialize() {
        vector<int> parents(NodeCount), order(NodeCount);
        int index = 0;
        stack<int> stack;
        stack.push(0);
        parents[0] = -1;
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            order[index++] = node;
            for (int adjacent : Adjacents[node]) {
                if (adjacent == parents[node]) {
                    continue;
                }
                stack.push(adjacent);
                parents[adjacent] = node;
            }
        }

        for (int i = order.size() - 1; i >= 1; i--) {
            int node = order[i];
            int parent = parents[node];
            T accum = Identity;
            int parentIndex = -1;
            for (int j = 0; j < Adjacents[node].size(); j++) {
                if (Adjacents[node][j] == parent) {
                    parentIndex = j;
                    continue;
                }
                accum = Operate(accum, DP[node][j]);
            }
            DP[parent][IndexForAdjacents[node][parentIndex]] = OperateNode(accum, node);
            accum = Operate(accum, DP[node][parentIndex]);
            DP[node][parentIndex] = accum;
        }

        for (int i = 0; i < order.size(); i++) {
            int node = order[i];
            T accum = Identity;
            vector<T> accumsFromTail(Adjacents[node].size());
            accumsFromTail[accumsFromTail.size() - 1] = Identity;
            for (int j = accumsFromTail.size() - 1; j >= 1; j--) {
                accumsFromTail[j - 1] = Operate(DP[node][j], accumsFromTail[j]);
            }
            for (int j = 0; j < accumsFromTail.size(); j++) {
                DP[Adjacents[node][j]][IndexForAdjacents[node][j]] = OperateNode(Operate(accum, accumsFromTail[j]), node);
                accum = Operate(accum, DP[node][j]);
            }
            Res[node] = OperateNode(accum, node);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }

    auto f = [m](T x, T y) { return T(int(x) * int(y) % m); };
    auto g = [](T v, int p) { return v + 1; };
    ReRootingSolver s(n, edges, 1, f, g);

    for (int i = 0; i < n; i++) {
        cout << s.Query(i) - 1 << "\n";
    }

    return 0;
}
