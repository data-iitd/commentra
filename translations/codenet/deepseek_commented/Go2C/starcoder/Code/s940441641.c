#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
#define REP_FROM(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define REP_TO(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define RANGE(i, n) REP(i, n)
#define RANGE1(i, n) REP1(i, n)
#define RANGE_FROM(i, m, n) REP_FROM(i, m, n)
#define RANGE_TO(i, m, n) REP_TO(i, m, n)

#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(ALL(x), greater<int>())
#define MIN(x) *min_element(ALL(x))
#define MAX(x) *max_element(ALL(x))
#define SUM(x) accumulate(ALL(x))
#define SUMLL(x) accumulate(ALL(x), 0LL)
#define SQR(x) ((x) * (x))
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<P> VP;
typedef vector<Pll> VPll;
typedef map<int, int> MII;
typedef map<ll, ll> MLL;

int H, W, K;
char **c;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int toID(int x, int y, int dir) {
	return 4 * (W * y + x) + dir;
}

void splatID(int id, int *x, int *y, int *dir) {
	*x = id / 4 % W;
	*y = id / 4 / W;
	*dir = id % 4;
}

int main() {
	scanf("%d%d%d", &H, &W, &K);
	c = (char **)malloc(sizeof(char *) * H);
	REP(y, H) {
		c[y] = (char *)malloc(sizeof(char) * W);
		scanf("%s", c[y]);
	}
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	int *dist = (int *)malloc(sizeof(int) * W * H * 4);
	REP(i, W * H * 4) {
		dist[i] = INT_MAX;
	}
	Heap q;
	REP(i, 4) {
		q.push(State{0, toID(x1, y1, i)});
	}
	while (q.size() > 0) {
		State now = q.pop();
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
			int nCost = (now.cost + K - 1) / K * K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.push(State{nCost, nID});
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.push(State{nCost, nID});
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
	return 0;
}

struct State {
	int cost, id;
};

struct HeapElement {
	State state;
};

struct Heap {
	HeapElement *data;
	int size;
	int capacity;
};

HeapElement *newHeapElement(State state) {
	HeapElement *e = (HeapElement *)malloc(sizeof(HeapElement));
	e->state = state;
	return e;
}

void deleteHeapElement(HeapElement *e) {
	free(e);
}

Heap newHeap() {
	Heap h;
	h.data = NULL;
	h.size = 0;
	h.capacity = 0;
	return h;
}

void deleteHeap(Heap *h) {
	free(h->data);
	h->data = NULL;
	h->size = 0;
	h->capacity = 0;
}

void heapify(Heap *h) {
	int i = h->size;
	while (i > 0) {
		int j = (i - 1) / 2;
		if (h->data[i].state.cost < h->data[j].state.cost) {
			HeapElement tmp = h->data[i];
			h->data[i] = h->data[j];
			h->data[j] = tmp;
		}
		i--;
	}
}

void push(Heap *h, State state) {
	if (h->size == h->capacity) {
		if (h->capacity == 0) {
			h->capacity = 1;
		} else {
			h->capacity *= 2;
		}
		HeapElement *data = (HeapElement *)realloc(h->data, sizeof(HeapElement) * h->capacity);
		assert(data!= NULL);
		h->data = data;
	}
	h->data[h->size] = newHeapElement(state);
	h->size++;
	heapify(h);
}

State pop(Heap *h) {
	assert(h->size > 0);
	State state = h->data[0].state;
	deleteHeapElement(h->data[0]);
	h->data[0] = h->data[h->size - 1];
	h->size--;
	heapify(h);
	return state;
}

int main() {
	scanf("%d%d%d", &H, &W, &K);
	c = (char **)malloc(sizeof(char *) * H);
	REP(y, H) {
		c[y] = (char *)malloc(sizeof(char) * W);
		scanf("%s", c[y]);
	}
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	int *dist = (int *)malloc(sizeof(int) * W * H * 4);
	REP(i, W * H * 4) {
		dist[i] = INT_MAX;
	}
	Heap q = newHeap();
	REP(i, 4) {
		push(&q, State{0, toID(x1, y1, i)});
	}
	while (q.size > 0) {
		State now = pop(&q);
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
			int nCost = (now.cost + K - 1) / K * K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) {
				continue;
			}
			push(&q, State{nCost, nID});
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) {
				continue;
			}
			push(&q, State{nCost, nID});
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
	return 0;
}

