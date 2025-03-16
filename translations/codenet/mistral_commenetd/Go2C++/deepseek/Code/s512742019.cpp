#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const int MOD = 1e9 + 7; // Modulus value for modular arithmetic
const long long INF = 1LL << 60; // Infinite value for comparison

struct Mon {
    int x, h;
};

struct Node {
    int x, h;
    bool operator>(const Node& other) const {
        return x > other.x;
    }
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.x > b.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, D, A;
    cin >> N >> D >> A;

    vector<Mon> M(N);
    for (int i = 0; i < N; ++i) {
        cin >> M[i].x >> M[i].h;
    }

    sort(M.begin(), M.end(), [](const Mon& a, const Mon& b) {
        return a.x < b.x;
    });

    priority_queue<Node, vector<Node>, CompareNode> q;
    long long ans = 0;
    long long total = 0;

    for (int i = 0; i < N; ++i) {
        Mon m = M[i];

        while (!q.empty() && q.top().x < m.x) {
            total -= q.top().h;
            q.pop();
        }

        if (total < m.h) {
            long long damage = m.h - total;
            ans += damage;
            q.push({m.x + 2 * D, damage});
            total += damage;
        }
    }

    cout << ans << '\n';

    return 0;
}

