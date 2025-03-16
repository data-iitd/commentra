
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    vector<string> c(H);
    for (int y = 0; y < H; y++) {
        cin >> c[y];
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    auto toID = [&](int x, int y, int dir) {
        return 4 * (W * y + x) + dir;
    };
    auto splatID = [&](int id) {
        return id / 4 % W, id / 4 / W, id % 4;
    };

    vector<int> dist(W * H * 4, 1 << 60);
    priority_queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push(State{0, toID(x1, y1, i)});
    }
    while (!q.empty()) {
        State now = q.top();
        q.pop();
        int x, y, dir;
        tie(x, y, dir) = splatID(now.ID);
        if (c[y][x] == '@') {
            continue;
        }
        if (dist[now.ID] <= now.Cost) {
            continue;
        }
        dist[now.ID] = now.Cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCost = (now.Cost + K - 1) / K * K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push(State{nCost, nID});
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.Cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push(State{nCost, nID});
        }
    }
    int ans = 1 << 60;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id] < ans) {
            int d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < 1 << 60) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

