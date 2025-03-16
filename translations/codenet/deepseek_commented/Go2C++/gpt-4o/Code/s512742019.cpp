#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Mon {
    int x, h;
};

int ceilDiv(int a, int b) {
    return (a + b - 1) / b; // Equivalent to ceil(a / b)
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

    queue<pair<int, int>> q; // Pair of (x, damage)
    int ans = 0;
    int total = 0;

    for (int i = 0; i < N; i++) {
        Mon m = M[i];

        // Remove monsters that are out of range
        while (!q.empty() && q.front().first < m.x) {
            total -= q.front().second;
            q.pop();
        }

        if (total < m.h) {
            m.h -= total;
            int count = ceilDiv(m.h, A);
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
