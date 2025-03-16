

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int Inf = 1 << 60;

int H, W, K;
int x1, y1, x2, y2;
vector<string> c;
vector<vector<int>> dist;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct State {
    int cost, id;
    bool operator<(const State& s) const {
        return cost > s.cost;
    }
};

void initDist() {
    dist.assign(H, vector<int>(W, Inf));
    priority_queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, i)});
    }
    while (!q.empty()) {
        auto s = q.top();
        q.pop();
        if (dist[s.id / W][s.id % W] <= s.cost) {
            continue;
        }
        dist[s.id / W][s.id % W] = s.cost;
        for (int i = 0; i < 4; i++) {
            int nx = s.id % W + dx[i], ny = s.id / W + dy[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                q.push({s.cost + 1, toID(nx, ny, i)});
            }
        }
        int nx = s.id % W + dx[s.id % 4], ny = s.id / W + dy[s.id % 4];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            q.push({s.cost + K, toID(nx, ny, s.id % 4)});
        }
    }
}

int toID(int x, int y, int dir) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int& x, int& y, int& dir) {
    x = id % W;
    y = id / W;
    dir = id % 4;
}

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    c.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> c[i];
    }
    initDist();
    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id / W][id % W] < ans) {
            ans = dist[id / W][id % W];
        }
    }
    cout << (ans < Inf? ans : -1) << endl;
    return 0;
}

C++:

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int Inf = 1 << 60;

int H, W, K;
int x1, y1, x2, y2;
vector<string> c;
vector<vector<int>> dist;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct State {
    int cost, id;
    bool operator<(const State& s) const {
        return cost > s.cost;
    }
};

void initDist() {
    dist.assign(H, vector<int>(W, Inf));
    priority_queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, i)});
    }
    while (!q.empty()) {
        auto s = q.top();
        q.pop();
        if (dist[s.id / W][s.id % W] <= s.cost) {
            continue;
        }
        dist[s.id / W][s.id % W] = s.cost;
        for (int i = 0; i < 4; i++) {
            int nx = s.id % W + dx[i], ny = s.id / W + dy[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                q.push({s.cost + 1, toID(nx, ny, s.id % 4)});
            }
        }
        int nx = s.id % W + dx[s.id % 4], ny = s.id / W + dy[s.id % 4];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            q.push({s.cost + K, toID(nx, ny, s.id % 4)});
        }
    }
    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id / W][id % W] < ans) {
            ans = dist[id / W][id % W];
        }
    }
    cout << (ans < Inf? ans : -1) << endl;
    return 0;
}

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    c.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> c[i];
    }
    initDist();
    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id / W][id % W] < ans) {
            ans = dist[id / W][id % W];
        }
    }
    cout << (ans < Inf? ans : -1) << endl;
    return 0;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct State {
    int cost, id;
    bool operator<(const State& s) const {
        return cost > s.cost;
    }
};

void initDist() {
    dist.assign(H, vector<int>(W, Inf));
    priority_queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, 0, 0});
    }
    while (!q.empty()) {
        auto s = q.top();
        q.pop();
        if (dist[s.id / W][s.id % W] < ans) {
            ans = dist[s.id / W][s.id % W]
        }
    }
    cout << (ans < Inf? ans : -1) << endl;
    return 0;
}

int toID(int x, int y, int dir) {
    return 4 * (W * y + x)
}

void splatID(int x, int y, int dir) {
    return 0;
}

int dx[4] = {1, 0, -1, 0};

int dy[4] = {0, 1, 0, -1};

struct State {
    int cost, id;
    bool operator<(const State& s) const {
        return cost > s.cost;
    }
};

void initDist() {
    dist.assign(H, vector<int>(W, Inf));
    priority_queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, 0, 0});
    }
    while (!q.empty()) {
        auto s = q.top();
        q.pop();
        if (dist[s.id / W][s.id % W] < ans) {
            ans = dist[s.id / W][s.id % W]
        }
    }
    cout << (ans < Inf? ans : -1) << endl;
    return 0;
}

int main() {
    int H, W, K;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    c.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> c[i]
    }
    initDist() {
    dist.assign(H, vector<int>(W, Inf));
    priority_queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, 0, 0});
    while (!q.empty()) {
        auto s = q.top();
        if (dist[s.id / W][s.id % W] < ans) {
            ans = dist[s.id / W][s.id % W]
        }
    }
    cout << (ans < Inf? ans : -1) << endl;
    return 0;
}

int toID(int x, int y, int dir) {
    return 0;
}

int dx[4] = {1, 0, -1, 0};

int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    c.resize(H)
    for (int i = 0; i < H; i++) {
        cin >> c[i]
    }
    initDist() {
    dist.assign(H, vector<int>(W, Inf));
    priority_queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, 0, 0})
    while (!q.empty()) {
        auto s = q.top();
        if (dist[s.id / W][s.id % W] < ans) {
            ans = dist[s.id / W][s.id % W]
        }
    }
    cout << (ans < Inf? ans : -1) << endl;
    return 0;
}

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    c.resize(H)
    for (int i = 0; i++) {
        cin >> c[i]
    }
    initDist() {
    dist.assign(H, vector<int>(W, Inf))
    priority_queue<State> q;
    for (int i = 0; i++) {
        q.push({0, toID(x1, y1, 0, -1)
    }
    while (!q.empty()) {
        auto s = q.top();
        if (dist[s.id / W][s.id % W] < ans) {
            ans = dist[s.id / W][s.id % W]
}

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    c.resize(H)
    for (int i = 0; i < H {
        return 0;
}

int dx[4] = {1, 0, -1, 0}

int dy[4] = {0, 1, 0, -1)

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    c.resize(H)
    for (int i = 0; i++) {
        q.push({0, toID(x1, y1, 0, -1)
    }
    while (!q.empty()) {
        auto s = q.top();
        if (dist[s.id / W][s.id % W] < ans) {
            ans = dist[s.id / W][s.id % W]
        }
    cout << (ans < Inf? ans : -1) << endl;
    return 0;
}

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    c.resize(H)
}

int dx[4] = {1, 0, -1, 0}

int dy[4] = {0, 1, 0, -1;

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    c.resize(H)
}

int dy[4] = {0, 1, 0, -1)
}

int main() {
    cin >> H >> W >> K;
    c.resize(H)
    for (int i = 0; i++) {
        q.push({0, toID(x1, y1, 0, -1)
}

int dy[4] = {0, 1, 0, -1)
}

int main() {
    cin >> H >> W >> K;
    c.resize(H)
    for (int i = 0; i++) {
        q.push({0, toID(x1, y1, 0, -1)
}

int dx[4] = {1, 0, -1)
}

int dy[4] = {0, 1, 0, -1)
}

int main() {
    cin >> H >> W >> K;
    c.resize(H)
}
int dx[4] = {0, 1, 0, -1)
}
int dy[4] = {0, 1, 0, -1)
}

int main() {
    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;
    c.resize(H)
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W >> K;
    c.resize(H)
}
int dx[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W >> K;
    c.resize(H)
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W >> K;
    c.push({0, 1, 0, -1)
}
int dx[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W >> K;
    c.push({0, 1, 0, -1)
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W >> K;
    c.push({0, 1, 0, -1)
}
int dx[4] = {0, 1, 0, -1)
}

int main() {
    cin >> H >> W >> K;
    c.resize(H)
}

int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W >> K;
    c.push({0, 1, 0, -1)
}
int dy[4] = {0, 1, 0, -1)
int dx[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W >> K;
    c.push({0, 1, 0, -1)
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W >> K;
    c.push({0, 1, 0)
}
int dx[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W)
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W
}
int dx[4] = {0, 1, 0, -1)
}
int dy[4] = {0, 1, 0, -1)
int main() {
    cin >> H >> W)
}
int dy[4] = {0, 1, 0, 0, -1)
}
int main() {
    cin >> H >> W
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W)
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W
}
int dy[4] = {0, 1, 0, 0, -1)
}
int main() {
    cin >> H >> W
}
int dy[4] = {0, 1, 0, -1)
}
int dx[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H >> W)
}
int dy[4] = {0, 1, 0, -1)
}
int dy[4] = {0, 1, 0, -1)
}
int main() {
    cin >> H
}
int dy[4] = {0, 1, 0, 1, 0, -1)
}
int dx[4] = {0, 1, 0, 0, 1, 0, 0, -1)
}
int dy[4] = {0, 1, 0, 1, 0, 0, 1)
}
int dx[4] = {0, 1, 0, 0, 1, 0, 0, 1, 0, -1)
}
int dy[4] = {0, 1, 0, 0, 1)
}
int dx[4] = {0, 1, 0, 0, -1)
}
int dy[4] = {0, 1, 0, 0, 1, 0,