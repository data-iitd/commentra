

#include <bits/stdc++.h>
using namespace std;

const int Inf = 1 << 60;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    vector<string> c(H);
    for (int y = 0; y < H; y++) {
        cin >> c[y];
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    function<int(int, int, int)> toID = [&](int x, int y, int dir) {
        return 4 * (W * y + x) + dir;
    };
    function<void(int, int, int)> splatID = [&](int id) {
        x = id / 4 % W;
        y = id / 4 / W;
        dir = id % 4;
    };

    vector<int> dist(W * H * 4, Inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, i)});
    }
    while (!q.empty()) {
        auto [cost, id] = q.top();
        q.pop();
        if (dist[id] <= cost) {
            continue;
        }
        dist[id] = cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCost = (cost + K - 1) / K * K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push({nCost, nID});
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push({nCost, nID});
        }
    }
    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id] < ans) {
            int d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < Inf) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

