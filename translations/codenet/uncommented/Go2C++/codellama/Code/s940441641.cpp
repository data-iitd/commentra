
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1 << 60;

int H, W, K;
int x1, y1, x2, y2;
vector<string> c;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int toID(int x, int y, int dir) {
	return 4*(W*y+x) + dir;
}

int splatID(int id) {
	return id / 4 % W, id / 4 / W, id % 4;
}

int dist[100000];

struct State {
	int cost, id;
};

struct HeapElement {
	int cost, id;
};

struct Heap {
	vector<HeapElement> v;
	bool operator()(const HeapElement& a, const HeapElement& b) {
		return a.cost < b.cost;
	}
};

void dijkstra() {
	Heap q;
	for (int i = 0; i < 4; i++) {
		q.v.push_back({0, toID(x1, y1, i)});
	}
	while (!q.v.empty()) {
		auto now = q.v.back();
		q.v.pop_back();
		int x, y, dir;
		tie(x, y, dir) = splatID(now.id);
		if (c[y][x] == '@') continue;
		if (dist[now.id] <= now.cost) continue;
		dist[now.id] = now.cost;
		if (x == x2 && y == y2) break;
		for (int i = 0; i < 4; i++) {
			int nCost = (now.cost + K - 1) / K * K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) continue;
			q.v.push_back({nCost, nID});
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) continue;
			q.v.push_back({nCost, nID});
		}
	}
}

int main() {
	cin >> H >> W >> K;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--; y1--; x2--; y2--;
	c.resize(H);
	for (int y = 0; y < H; y++) {
		cin >> c[y];
	}

	dijkstra();

	int ans = INF;
	for (int i = 0; i < 4; i++) {
		int id = toID(x2, y2, i);
		if (dist[id] < ans) {
			int d2 = (dist[id] + K - 1) / K;
			if (d2 < ans) ans = d2;
		}
	}
	if (ans < INF) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
}

