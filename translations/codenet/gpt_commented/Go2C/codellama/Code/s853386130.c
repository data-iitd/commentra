
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 1000000007

int mod = 1000000007;
int INF = 1000000007;

int min(int x, int y) {
	if (x < y) {
		return x;
	}
	return y;
}

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}

int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}

int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}

int pow(int a, int n) {
	int ret = 1;
	for (int i = 1; i <= n; i++) {
		ret *= a;
	}
	return ret;
}

int modpow(int a, int n, int mod) {
	int res = 1;
	for (int i = 0; i < n; i++) {
		res = res * a % mod;
	}
	return res;
}

int modinv(int n, int mod) {
	return modpow(n, mod - 2, mod);
}

int modcomb(int n, int a, int mod) {
	int x = 1;
	int y = 1;
	for (int i = 0; i < a; i++) {
		x = x * (n - i) % mod;
		y = y * (i + 1) % mod;
	}
	return x * modpow(y, mod - 2, mod) % mod;
}

int modfactorial(int n, int mod) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = (result * i) % mod;
	}
	return result;
}

typedef struct {
	int *d;
	int mod;
} unionFind;

unionFind newUnionFind(int n) {
	unionFind uf;
	uf.d = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		uf.d[i] = -1; // Initialize each node as its own root
	}
	return uf;
}

int find(unionFind uf, int x) {
	if (uf.d[x] < 0) {
		return x;
	}
	uf.d[x] = find(uf, uf.d[x]); // Path compression
	return uf.d[x];
}

int unite(unionFind uf, int x, int y) {
	int rootX = find(uf, x);
	int rootY = find(uf, y);
	if (rootX == rootY) {
		return 0; // x and y are already in the same set
	}

	// Union by size
	if (uf.d[rootX] < uf.d[rootY]) {
		uf.d[rootX] += uf.d[rootY];
		uf.d[rootY] = rootX;
	} else {
		uf.d[rootY] += uf.d[rootX];
		uf.d[rootX] = rootY;
	}

	return 1;
}

int same(unionFind uf, int x, int y) {
	return find(uf, x) == find(uf, y);
}

int size(unionFind uf, int x) {
	return -uf.d[find(uf, x)];
}

typedef struct {
	int *facts;
	int *invs;
	int mod;
} Combination;

Combination NewCombination(int n, int mod) {
	Combination cmb;
	cmb.facts = (int *)malloc((n + 1) * sizeof(int));
	cmb.invs = (int *)malloc((n + 1) * sizeof(int));
	cmb.mod = mod;
	return cmb;
}

int calc(Combination cmb, int n, int k) {
	int ret = cmb.facts[n] * cmb.invs[k];
	ret %= cmb.mod;
	ret = ret * cmb.invs[n - k] % cmb.mod;
	return ret;
}

void init(Combination cmb, int n) {
	cmb.facts[0] = 1;
	// Calculate factorials
	for (int i = 1; i <= n; i++) {
		cmb.facts[i] = cmb.facts[i - 1] * i % cmb.mod;
	}
	// Calculate inverses using modular inverse
	cmb.invs[n] = modinv(cmb.facts[n], cmb.mod);
	for (int i = n - 1; i >= 0; i--) {
		cmb.invs[i] = cmb.invs[i + 1] * (i + 1) % cmb.mod;
	}
}

typedef struct {
	int *data;
	int size;
	int capacity;
} Queue;

Queue newQueue(int capacity) {
	Queue q;
	q.data = (int *)malloc(capacity * sizeof(int));
	q.size = 0;
	q.capacity = capacity;
	return q;
}

int empty(Queue q) {
	return q.size == 0;
}

void push(Queue *q, int i) {
	if (q->size == q->capacity) {
		q->capacity *= 2;
		q->data = (int *)realloc(q->data, q->capacity * sizeof(int));
	}
	q->data[q->size++] = i;
}

int pop(Queue *q) {
	if (empty(*q)) {
		return 0;
	} else {
		int res = q->data[0];
		for (int i = 0; i < q->size - 1; i++) {
			q->data[i] = q->data[i + 1];
		}
		q->size--;
		return res;
	}
}

typedef struct {
	int *data;
	int size;
	int capacity;
} Stack;

Stack newStack(int capacity) {
	Stack s;
	s.data = (int *)malloc(capacity * sizeof(int));
	s.size = 0;
	s.capacity = capacity;
	return s;
}

int empty(Stack s) {
	return s.size == 0;
}

void push(Stack *s, int i) {
	if (s->size == s->capacity) {
		s->capacity *= 2;
		s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
	}
	s->data[s->size++] = i;
}

int pop(Stack *s) {
	if (empty(*s)) {
		return 0;
	} else {
		int res = s->data[s->size - 1];
		s->size--;
		return res;
	}
}

typedef struct {
	int *data;
	int size;
	int capacity;
} intHeap;

intHeap newHeap(int capacity) {
	intHeap h;
	h.data = (int *)malloc(capacity * sizeof(int));
	h.size = 0;
	h.capacity = capacity;
	return h;
}

void push(intHeap *h, int x) {
	if (h->size == h->capacity) {
		h->capacity *= 2;
		h->data = (int *)realloc(h->data, h->capacity * sizeof(int));
	}
	h->data[h->size++] = x;
}

int pop(intHeap *h) {
	if (h->size == 0) {
		return 0;
	} else {
		int res = h->data[0];
		for (int i = 0; i < h->size - 1; i++) {
			h->data[i] = h->data[i + 1];
		}
		h->size--;
		return res;
	}
}

typedef struct {
	int x;
	int y;
} point;

typedef struct {
	point *data;
	int size;
	int capacity;
} points;

points newPoints(int capacity) {
	points p;
	p.data = (point *)malloc(capacity * sizeof(point));
	p.size = 0;
	p.capacity = capacity;
	return p;
}

int Len(points p) {
	return p.size;
}

int Less(points p, int i, int j) {
	return p.data[i].x < p.data[j].x;
}

void Swap(points p, int i, int j) {
	point tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

int main() {
	// Initialize a buffered reader to read input
	FILE *r = stdin;
	int n, m, R;

	// Read the number of nodes (n), edges (m), and the number of required nodes (R)
	fscanf(r, "%d", &n);
	fscanf(r, "%d", &m);
	fscanf(r, "%d", &R);

	// Read the required nodes and adjust for 0-based indexing
	int *rs = (int *)malloc(R * sizeof(int));
	for (int i = 0; i < R; i++) {
		fscanf(r, "%d", &rs[i]);
		rs[i]--;
	}

	// Initialize the cost matrix with INF values
	int **costs = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		costs[i] = (int *)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			costs[i][j] = INF;
		}
		costs[i][i] = 0; // The cost to reach itself is 0
	}

	// Read the edges and their costs
	int a, b, c;
	for (int i = 0; i < m; i++) {
		fscanf(r, "%d", &a);
		fscanf(r, "%d", &b);
		fscanf(r, "%d", &c);
		a--;
		b--;
		costs[a][b] = c; // Set cost for edge a to b
		costs[b][a] = c; // Set cost for edge b to a (undirected graph)
	}

	// Calculate the shortest paths using the Floyd-Warshall algorithm
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}

	// Generate all permutations of the required nodes
	int **perms = (int **)malloc(R * sizeof(int *));
	for (int i = 0; i < R; i++) {
		perms[i] = (int *)malloc(R * sizeof(int));
		for (int j = 0; j < R; j++) {
			perms[i][j] = rs[j];
		}
	}
	int *tmp = (int *)malloc(R * sizeof(int));
	for (int i = 0; i < R; i++) {
		for (int j = 1; j < R; j++) {
			tmp[j] = perms[i][j];
		}
		for (int j = 1; j < R; j++) {
			perms[i][j] = tmp[j - 1];
		}
		perms[i][0] = tmp[R - 1];
	}
	free(tmp);

	// Evaluate each permutation to find the minimum cost path
	int ans = INF;
	for (int i = 0; i < R; i++) {
		int tmp = 0;
		for (int j = 1; j < R; j++) {
			int from = perms[i][j - 1];
			int to = perms[i][j];
			tmp += costs[from][to]; // Accumulate the cost of the current permutation
		}
		ans = min(ans, tmp); // Update the answer with the minimum cost found
	}

	// Output the minimum cost
	printf("%d\n", ans);
	return 0;
}

