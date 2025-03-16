#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP3(i, m, n) for (int i = (m); i < (int)(n); i++)

#define MAX_H 1000
#define MAX_W 1000
#define MAX_K 1000000000

typedef struct {
	int x, y, dir;
} State;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int toID(int x, int y, int dir) {
	return 4*(MAX_W*y+x) + dir;
}

void splatID(int id, int *x, int *y, int *dir) {
	*x = id / 4 % MAX_W;
	*y = id / 4 / MAX_W;
	*dir = id % 4;
}

int main() {
	int H, W, K;
	scanf("%d%d%d", &H, &W, &K);
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	char c[MAX_H][MAX_W];
	REP(y, H) {
		scanf("%s", c[y]);
	}

	int dist[MAX_H][MAX_W][4];
	REP(i, MAX_H*MAX_W*4) {
		dist[i] = INT_MAX;
	}

	State q[MAX_H*MAX_W*4];
	int q_size = 0;
	REP(i, 4) {
		q[q_size++] = (State){0, toID(x1, y1, i), 0};
	}
	while (q_size > 0) {
		State now = q[--q_size];
		int x, y, dir;
		splatID(now.id, &x, &y, &dir);
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
		REP(i, 4) {
			int n_cost = (now.cost + K - 1) / K * K;
			int n_id = toID(x, y, i);
			if (dist[n_id] <= n_cost) {
				continue;
			}
			q[q_size++] = (State){n_cost, n_id, 0};
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int n_cost = now.cost + 1;
			int n_id = toID(nx, ny, dir);
			if (dist[n_id] <= n_cost) {
				continue;
			}
			q[q_size++] = (State){n_cost, n_id, 0};
		}
	}
	int ans = INT_MAX;
	REP(i, 4) {
		int id = toID(x2, y2, i);
		if (dist[id] < ans) {
			int d2 = (dist[id] + K - 1) / K;
			if (d2 < ans) {
				ans = d2;
			}
		}
	}
	if (ans < INT_MAX) {
		printf("%d\n", ans);
	} else {
		printf("-1\n");
	}
}

