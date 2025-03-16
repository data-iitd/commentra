#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Mon {
    int x, h;
};

struct Node {
    int x, h;
};

int ceil(int a, int b) {
    return (a + b - 1) / b; // Equivalent to (a + b - 1) / b
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D, A;
    cin >> N >> D >> A;
    vector<Mon> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i].x >> M[i].h;
    }

    sort(M.begin(), M.end(), [](const Mon &a, const Mon &b) {
        return a.x < b.x;
    });

    queue<Node> q;
    int ans = 0;
    long long total = 0; // Use long long to avoid overflow

    for (int i = 0; i < N; i++) {
        Mon m = M[i];
        while (!q.empty() && q.front().x < m.x) {
            total -= q.front().h;
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

    cout << ans << '\n';
    return 0;
}

// <END-OF-CODE>
