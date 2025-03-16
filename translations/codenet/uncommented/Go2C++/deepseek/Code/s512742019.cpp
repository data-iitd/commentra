#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Mon {
    int x, h;
};

struct Node {
    int x, h;
};

struct CompareMon {
    bool operator()(Mon const& a, Mon const& b) {
        return a.x < b.x;
    }
};

struct CompareNode {
    bool operator()(Node const& a, Node const& b) {
        return a.x < b.x;
    }
};

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    int N, D, A;
    cin >> N >> D >> A;
    vector<Mon> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i].x >> M[i].h;
    }
    sort(M.begin(), M.end(), CompareMon());
    priority_queue<Node, vector<Node>, CompareNode> q;
    long long ans = 0;
    long long total = 0;
    for (int i = 0; i < N; i++) {
        Mon m = M[i];
        while (!q.empty() && q.top().x < m.x) {
            total -= q.top().h;
            q.pop();
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceil(m.h, A);
            ans += count;
            int damage = count * A;
            q.push({m.x + 2 * D, damage});
            total += damage;
        }
    }

    cout << ans << endl;
    return 0;
}

