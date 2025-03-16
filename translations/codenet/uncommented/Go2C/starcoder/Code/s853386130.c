#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#define mod 1000000007
#define INF 1000000007

typedef struct {
	int *d;
	int n;
} UnionFind;

UnionFind *newUnionFind(int n) {
	UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));
	uf->d = (int *)malloc(sizeof(int) * n);
	uf->n = n;
	for (int i = 0; i < n; i++) {
		uf->d[i] = -1;
	}
	return uf;
}

int find(UnionFind *uf, int x) {
	if (uf->d[x] < 0) {
		return x;
	}
	uf->d[x] = find(uf, uf->d[x]);
	return uf->d[x];
}

bool unite(UnionFind *uf, int x, int y) {
	int rootX = find(uf, x);
	int rootY = find(uf, y);
	if (rootX == rootY) {
		return false;
	}

	if (uf->d[rootX] < uf->d[rootY]) {
		uf->d[rootX] += uf->d[rootY];
		uf->d[rootY] = rootX;
	} else {
		uf->d[rootY] += uf->d[rootX];
		uf->d[rootX] = rootY;
	}

	return true;
}

bool same(UnionFind *uf, int x, int y) {
	return find(uf, x) == find(uf, y);
}

int size(UnionFind *uf, int x) {
	return -uf->d[find(uf, x)];
}

void freeUnionFind(UnionFind *uf) {
	free(uf->d);
	free(uf);
}

int modpow(int a, int n, int mod) {
	int res = 1;
	for (int i = 0; i < n; i++) {
		if (n & (1 << i)) {
			res = res * a % mod;
		}
		a = a * a % mod;
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
	int *facts;
	int *invs;
	int mod;
} Combination;

Combination *newCombination(int n, int mod) {
	Combination *cmb = (Combination *)malloc(sizeof(Combination));
	cmb->facts = (int *)malloc(sizeof(int) * (n + 1));
	cmb->invs = (int *)malloc(sizeof(int) * (n + 1));
	cmb->mod = mod;
	return cmb;
}

int calc(Combination *cmb, int n, int k) {
	int ret = cmb->facts[n] * cmb->invs[k];
	ret %= cmb->mod;
	ret = ret * cmb->invs[n - k];
	ret %= cmb->mod;
	return ret;
}

void init(Combination *cmb, int n) {
	cmb->facts[0] = 1;
	for (int i = 1; i <= n; i++) {
		cmb->facts[i] = cmb->facts[i - 1] * i % cmb->mod;
	}
	cmb->invs[n] = modinv(cmb->facts[n], cmb->mod);
	for (int i = n - 1; i >= 0; i--) {
		cmb->invs[i] = cmb->invs[i + 1] * (i + 1) % cmb->mod;
	}
}

void freeCombination(Combination *cmb) {
	free(cmb->facts);
	free(cmb->invs);
	free(cmb);
}

typedef struct {
	int *d;
	int n;
} Queue;

Queue *newQueue(int n) {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->d = (int *)malloc(sizeof(int) * n);
	q->n = n;
	return q;
}

bool empty(Queue *q) {
	return q->n == 0;
}

void push(Queue *q, int i) {
	q->d[q->n] = i;
	q->n++;
}

int pop(Queue *q) {
	assert(!empty(q));
	q->n--;
	return q->d[q->n];
}

void freeQueue(Queue *q) {
	free(q->d);
	free(q);
}

typedef struct {
	int *d;
	int n;
} Stack;

Stack *newStack(int n) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->d = (int *)malloc(sizeof(int) * n);
	s->n = n;
	return s;
}

bool empty(Stack *s) {
	return s->n == 0;
}

void push(Stack *s, int i) {
	s->d[s->n] = i;
	s->n++;
}

int pop(Stack *s) {
	assert(!empty(s));
	s->n--;
	return s->d[s->n];
}

void freeStack(Stack *s) {
	free(s->d);
	free(s);
}

typedef struct {
	int *d;
	int n;
} PriorityQueue;

PriorityQueue *newPriorityQueue(int n) {
	PriorityQueue *q = (PriorityQueue *)malloc(sizeof(PriorityQueue));
	q->d = (int *)malloc(sizeof(int) * n);
	q->n = n;
	return q;
}

bool empty(PriorityQueue *q) {
	return q->n == 0;
}

void push(PriorityQueue *q, int i) {
	q->d[q->n] = i;
	q->n++;
}

int pop(PriorityQueue *q) {
	assert(!empty(q));
	q->n--;
	int res = q->d[0];
	q->d[0] = q->d[q->n];
	return res;
}

void freePriorityQueue(PriorityQueue *q) {
	free(q->d);
	free(q);
}

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point *d;
	int n;
} Points;

Points *newPoints(int n) {
	Points *p = (Points *)malloc(sizeof(Points));
	p->d = (Point *)malloc(sizeof(Point) * n);
	p->n = n;
	return p;
}

int len(Points *p) {
	return p->n;
}

bool less(Points *p, int i, int j) {
	return p->d[i].x < p->d[j].x;
}

void swap(Points *p, int i, int j) {
	Point tmp = p->d[i];
	p->d[i] = p->d[j];
	p->d[j] = tmp;
}

void freePoints(Points *p) {
	free(p->d);
	free(p);
}

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

typedef struct {
	int *d;
	int n;
} PrimeFactor;

PrimeFactor *newPrimeFactor(int n) {
	PrimeFactor *pf = (PrimeFactor *)malloc(sizeof(PrimeFactor));
	pf->d = (int *)malloc(sizeof(int) * n);
	pf->n = n;
	return pf;
}

void freePrimeFactor(PrimeFactor *pf) {
	free(pf->d);
	free(pf);
}

void primeFactor(int x, PrimeFactor *pf) {
	for (int i = 0; i < pf->n; i++) {
		pf->d[i] = 0;
	}
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			pf->d[i]++;
			x = x / i;
		}
	}
	if (x!= 1) {
		pf->d[x] = 1;
	}
}

typedef struct {
	int *d;
	int n;
} Divisor;

Divisor *newDivisor(int n) {
	Divisor *div = (Divisor *)malloc(sizeof(Divisor));
	div->d = (int *)malloc(sizeof(int) * n);
	div->n = n;
	return div;
}

void freeDivisor(Divisor *div) {
	free(div->d);
	free(div);
}

void divisor(int x, Divisor *div) {
	for (int i = 0; i < div->n; i++) {
		div->d[i] = 0;
	}
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			div->d[i]++;
			if (i * i!= x) {
				div->d[x / i]++;
			}
		}
	}
}

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}

char *reverseString(char *s) {
	char *r = (char *)malloc(sizeof(char) * (strlen(s) + 1));
	for (int i = 0; i < strlen(s); i++) {
		r[i] = s[strlen(s) - i - 1];
	}
	r[strlen(s)] = '\0';
	return r;
}

int pow(int a, int n) {
	int ret = 1;
	for (int i = 0; i < n; i++) {
		ret *= a;
	}
	return ret;
}

int main() {
	int n, m, R;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &R);

	int *rs = (int *)malloc(sizeof(int) * R);
	for (int i = 0; i < R; i++) {
		scanf("%d", &rs[i]);
		rs[i]--;
	}

	int **costs = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++) {
		costs[i] = (int *)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			costs[i][j] = INF;
		}
		costs[i][i] = 0;
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		a--;
		b--;
		costs[a][b] = c;
		costs[b][a] = c;
	}

	// Warshall-Floyd
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}

	// permutations
	Combination *cmb = newCombination(R, mod);
	cmb->init(R);
	int **perms = (int **)malloc(sizeof(int *) * cmb->facts[R]);
	for (int i = 0; i < cmb->facts[R]; i++) {
		perms[i] = (int *)malloc(sizeof(int) * R);
	}
	int *perm = (int *)malloc(sizeof(int) * R);
	for (int i = 0; i < R; i++) {
		perm[i] = rs[i];
	}
	for (int i = 0; i < cmb->facts[R]; i++) {
		for (int j = 0; j < R; j++) {
			perms[i][j] = perm[j];
		}
		for (int j = 1; j < R; j++) {
			int k = rand() % (j + 1);
			int tmp = perms[i][j];
			perms[i][j] = perms[i][k];
			perms[i][k] = tmp;
		}
	}
	freeCombination(cmb);

	int ans = INF;
	for (int i = 0; i < cmb->facts[R]; i++) {
		int tmp = 0;
		for (int j = 1; j < R; j++) {
			int from = perms[i][j-1];
			int to = perms[i][j];
			tmp += costs[from][to];
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);

	free(rs);
	for (int i = 0; i < n; i++) {
		free(costs[i]);
	}
	free(costs);
	for (int i = 0; i < cmb->facts[R]; i++) {
		free(perms[i]);
	}
	free(perms);
	free(perm);
	freeCombination(cmb);
	return 0;
}

