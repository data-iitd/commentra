#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int H, W, K;
int x1, y1, x2, y2;
string c[100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int toID(int x, int y, int dir) {
	return 4*(W*y+x) + dir;
}

void splatID(int id, int &x, int &y, int &dir) {
	x = id / 4 % W;
	y = id / 4 / W;
	dir = id % 4;
}

int dist[10000];

int main() {
	scanf("%d%d%d", &H, &W, &K);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	for (int y = 0; y < H; y++) {
		scanf("%s", c[y].data());
	}

	priority_queue<State> q;
	for (int i = 0; i < 4; i++) {
		q.push(State{0, toID(x1, y1, i)});
	}
	while (!q.empty()) {
		State now = q.top();
		q.pop();
		int x, y, dir;
		splatID(now.ID, x, y, dir);
		if (c[y][x] == '@') continue;
		if (dist[now.ID] <= now.Cost) continue;
		dist[now.ID] = now.Cost;
		if (x == x2 && y == y2) break;
		for (int i = 0; i < 4; i++) {
			int nCost = (now.Cost + K - 1) / K * K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) continue;
			q.push(State{nCost, nID});
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.Cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) continue;
			q.push(State{nCost, nID});
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
		printf("%d\n", ans);
	} else {
		printf("-1\n");
	}
}

struct State {
	int Cost, ID;
	bool operator < (const State &rhs) const {
		return Cost < rhs.Cost;
	}
};

typedef State HeapElement;
typedef vector<HeapElement> Heap;

