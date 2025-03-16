#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1LL << 60; // Define a constant for infinity

struct State {
    long long cost;
    int id;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

using MinHeap = priority_queue<State, vector<State>, greater<State>>;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--; y1--; x2--; y2--; // Adjust for 0-based indexing
    swap(x1, y1); swap(x2, y2); // Swap x and y for the starting and ending points

    vector<string> c(H);
    for (int y = 0; y < H; y++) {
        cin >> c[y];
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    auto toID = [](int x, int y, int dir) {
        return 4 * (W * y + x) + dir;
    };

    auto splatID = [](int id) {
        return make_tuple(id / 4 % W, id / 4 / W, id % 4);
    };

    vector<long long> dist(W * H * 4, INF);
    MinHeap q;

    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, i)});
    }

    while (!q.empty()) {
        State now = q.top();
        q.pop();
        int x, y, dir;
        tie(x, y, dir) = splatID(now.id);

        if (c[y][x] == '@') continue;
        if (dist[now.id] <= now.cost) continue;
        dist[now.id] = now.cost;

        if (x == x2 && y == y2) break;

        for (int i = 0; i < 4; i++) {
            long long nCost = (now.cost + K - 1) / K * K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost) continue;
            q.push({nCost, nID});
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            long long nCost = now.cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost) continue;
            q.push({nCost, nID});
        }
    }

    long long ans = INF;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id] < ans) {
            long long d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }

    if (ans < INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
