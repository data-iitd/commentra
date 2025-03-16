
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MOD = 100000007;
const int INF = 1 << 60;

struct Mon {
    int x, h;
    bool operator<(const Mon& m) const {
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

    queue<Node> q;
    int ans = 0;
    int total = 0;
    for (int i = 0; i < N; i++) {
        while (!q.empty() && q.front().x < M[i].x) {
            total -= q.front().h;
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

