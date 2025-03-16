#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const long long Inf = 1LL << 60;

struct State {
    long long Cost;
    int ID;
    bool operator>(const State& other) const {
        return Cost > other.Cost;
    }
};

int toID(int x, int y, int dir, int W) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int& x, int& y, int& dir, int W) {
    x = (id / 4) % W;
    y = (id / 4) / W;
    dir = id % 4;
}

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--; // Convert to 0-based indexing
    swap(x1, y1);
    swap(x2, y2);

    vector<string> c(H);
    for (int y = 0; y < H; y++) {
        cin >> c[y];
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<long long> dist(W * H * 4, Inf);
    priority_queue<State, vector<State>, greater<State>> q;

    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, i, W)});
    }

    while (!q.empty()) {
        State now = q.top();
        q.pop();
        int x, y, dir;
        splatID(now.ID, x, y, dir, W);

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
            long long nCost = (now.Cost + K - 1) / K * K;
            int nID = toID(x, y, i, W);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push({nCost, nID});
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            long long nCost = now.Cost + 1;
            int nID = toID(nx, ny, dir, W);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push({nCost, nID});
        }
    }

    long long ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i, W);
        if (dist[id] < ans) {
            long long d2 = (dist[id] + K - 1) / K;
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

// <END-OF-CODE>
