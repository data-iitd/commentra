
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct State {
    int cost, x, y, dir;
    bool operator<(const State &s) const {
        return cost > s.cost;
    }
};

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    vector<string> c(H);
    for (int i = 0; i < H; i++) {
        cin >> c[i];
    }

    priority_queue<State> que;
    for (int i = 0; i < 4; i++) {
        que.push({0, x1, y1, i});
    }

    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4, 1e9)));
    while (!que.empty()) {
        auto s = que.top();
        que.pop();
        if (dist[s.y][s.x][s.dir] <= s.cost) {
            continue;
        }
        dist[s.y][s.x][s.dir] = s.cost;
        if (s.x == x2 && s.y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i], ny = s.y + dy[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H && c[ny][nx]!= '@') {
                que.push({s.cost, nx, ny, i});
            }
        }
        int nx = s.x + dx[s.dir], ny = s.y + dy[s.dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H && c[ny][nx]!= '@') {
            que.push({s.cost + 1, nx, ny, s.dir});
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, (dist[y2][x2][i] + K - 1) / K);
    }
    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}

