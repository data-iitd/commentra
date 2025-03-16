
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Mon {
    int x, h;
    bool operator<(const Mon &m) const {
        return x < m.x;
    }
};

struct Node {
    int x, h;
};

int main() {
    int N, D, A;
    cin >> N >> D >> A;
    vector<Mon> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i].x >> M[i].h;
    }
    sort(M.begin(), M.end());
    priority_queue<Node> q;
    int ans = 0, total = 0;
    for (int i = 0; i < N; i++) {
        while (!q.empty() && q.top().x < M[i].x) {
            total -= q.top().h;
            q.pop();
        }
        if (total < M[i].h) {
            M[i].h -= total;
            int count = (M[i].h + A - 1) / A;
            ans += count;
            int damage = count * A;
            q.push({M[i].x + 2 * D, damage});
            total += damage;
        }
    }
    cout << ans << endl;
    return 0;
}

