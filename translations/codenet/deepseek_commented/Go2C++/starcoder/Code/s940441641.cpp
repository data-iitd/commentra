#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 60;

int H, W, K;
int x1, y1, x2, y2;
string c[100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int toID(int x, int y, int dir) {
	return 4 * (W * y + x) + dir;
}

void splatID(int id, int &x, int &y, int &dir) {
	x = id / 4 % W;
	y = id / 4 / W;
	dir = id % 4;
}

int main() {
	cin >> H >> W >> K;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--;
	y1--;
	x2--;
	y2--;
	for (int y = 0; y < H; y++) {
		cin >> c[y];
	}

	int dist[10000];
	for (int i = 0; i < 10000; i++) {
		dist[i] = INF;
	}

	struct State {
		int cost, id;
	};

	struct HeapElement {
		State state;
		bool operator<(const HeapElement &other) const {
			return state.cost < other.state.cost;
		}
	};

	priority_queue<HeapElement> q;
	for (int i = 0; i < 4; i++) {
		q.push({State{0, toID(x1, y1, i)}, false});
	}
	while (!q.empty()) {
		State now = q.top().state;
		q.pop();
		int x, y, dir;
		splatID(now.id, x, y, dir);
		if (c[y][x] == '@') {
			continue;
		}
		if (dist[now.id] <= now.cost) {
			continue;
		}
		dist[now.id] = now.cost;
		if (x == x2 && y == y2) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nCost = (now.cost + K - 1) / K * K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.push({State{nCost, nID}, false});
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.push({State{nCost, nID}, false});
		}
	}
	int ans = INF;
	for (int i = 0; i < 4; i++) {
		int id = toID(x2, y2, i);
		if (dist[id] < ans) {
			int d2 = (dist[id] + K - 1) / K;
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
}

