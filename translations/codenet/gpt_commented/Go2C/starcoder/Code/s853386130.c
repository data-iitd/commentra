

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MOD 1000000007
#define INF 1000000007

// Union-Find structure for disjoint set operations
typedef struct {
	int *d;
} union_find;

// newUnionFind initializes a new Union-Find structure
union_find *new_union_find(int n) {
	union_find *uf = (union_find *) malloc(sizeof(union_find));
	uf->d = (int *) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		uf->d[i] = -1; // Initialize each node as its own root
	}
	return uf;
}

// find finds the root of the set containing x
int find(union_find *uf, int x) {
	if (uf->d[x] < 0) {
		return x;
	}
	uf->d[x] = find(uf, uf->d[x]); // Path compression
	return uf->d[x];
}

// unite merges the sets containing x and y
bool unite(union_find *uf, int x, int y) {
	int rootX = find(uf, x);
	int rootY = find(uf, y);
	if (rootX == rootY) {
		return false; // x and y are already in the same set
	}

	// Union by size
	if (uf->d[rootX] < uf->d[rootY]) {
		uf->d[rootX] += uf->d[rootY];
		uf->d[rootY] = rootX;
	} else {
		uf->d[rootY] += uf->d[rootX];
		uf->d[rootX] = rootY;
	}

	return true;
}

// same checks if x and y are in the same set
bool same(union_find *uf, int x, int y) {
	return find(uf, x) == find(uf, y);
}

// size returns the size of the set containing x
int size(union_find *uf, int x) {
	return -uf->d[find(uf, x)];
}

// modpow calculates (a^n) % mod using exponentiation by squaring
int modpow(int a, int n, int mod) {
	int res = 1;
	for (int i = 0; i < 31; i++) {
		if (n & (1 << i)) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
	}
	return res;
}

// modinv calculates the modular inverse of n % mod
int modinv(int n, int mod) {
	return modpow(n, mod - 2, mod);
}

// modcomb calculates n choose a (nCk) % mod
int modcomb(int n, int a, int mod) {
	int x = 1;
	int y = 1;
	for (int i = 0; i < a; i++) {
		x = (x * (n - i)) % mod;
		y = (y * (i + 1)) % mod;
	}
	return (x * modinv(y, mod)) % mod;
}

// modfactorial calculates n! % mod
int modfactorial(int n, int mod) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = (result * i) % mod;
	}
	return result;
}

// Combination structure for precomputed factorials and inverses
typedef struct {
	int *facts;
	int *invs;
	int mod;
} combination;

// NewCombination initializes a new Combination structure
combination *new_combination(int n, int mod) {
	combination *cmb = (combination *) malloc(sizeof(combination));
	cmb->facts = (int *) malloc((n + 1) * sizeof(int));
	cmb->invs = (int *) malloc((n + 1) * sizeof(int));
	cmb->mod = mod;
	return cmb;
}

// calc computes n choose k (nCk) using precomputed values
int calc(combination *cmb, int n, int k) {
	int ret = cmb->facts[n] * cmb->invs[k];
	ret %= cmb->mod;
	ret = ret * cmb->invs[n - k];
	ret %= cmb->mod;
	return ret;
}

// init precomputes factorials and their inverses
void init(combination *cmb, int n) {
	cmb->facts[0] = 1;
	// Calculate factorials
	for (int i = 1; i <= n; i++) {
		cmb->facts[i] = cmb->facts[i - 1] * i % cmb->mod;
	}
	// Calculate inverses using modular inverse
	cmb->invs[n] = modinv(cmb->facts[n], cmb->mod);
	for (int i = n - 1; i >= 0; i--) {
		cmb->invs[i] = cmb->invs[i + 1] * (i + 1) % cmb->mod;
	}
}

// Utility functions

// min returns the smaller of two integers
int min(int x, int y) {
	if (x < y) {
		return x;
	}
	return y;
}

// max returns the larger of two integers
int max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}

// abs returns the absolute value of an integer
int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// primeFactor returns the prime factorization of x
void primeFactor(int x, int *res) {
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			res[i]++;
			x = x / i;
		}
	}
	if (x!= 1) {
		res[x] = 1;
	}
}

// divisor returns all divisors of x
void divisor(int x, int *res) {
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			res[0]++;
			if (i!= x / i) {
				res[0]++;
			}
		}
	}
}

// gcd returns the greatest common divisor of x and y
int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

// lcm returns the least common multiple of x and y
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}

// reverseString returns the reversed version of a string
void reverseString(char *s) {
	int i = 0;
	int j = strlen(s) - 1;
	char tmp;
	while (i < j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

// pow calculates a raised to the power of n
int pow(int a, int n) {
	int ret = 1;
	for (int i = 1; i <= n; i++) {
		ret *= a;
	}
	return ret;
}

// Queue structure for implementing a queue
typedef struct {
	int *data;
	int size;
	int front;
	int rear;
} queue;

// newQueue initializes a new queue
queue *new_queue(int size) {
	queue *q = (queue *) malloc(sizeof(queue));
	q->data = (int *) malloc(size * sizeof(int));
	q->size = size;
	q->front = 0;
	q->rear = 0;
	return q;
}

// empty checks if the queue is empty
bool empty(queue *q) {
	return q->front == q->rear;
}

// full checks if the queue is full
bool full(queue *q) {
	return (q->rear + 1) % q->size == q->front;
}

// push adds an element to the queue
void push(queue *q, int i) {
	if (full(q)) {
		return;
	}
	q->data[q->rear] = i;
	q->rear = (q->rear + 1) % q->size;
}

// pop removes and returns the front element of the queue
int pop(queue *q) {
	if (empty(q)) {
		return 0;
	}
	int res = q->data[q->front];
	q->front = (q->front + 1) % q->size;
	return res;
}

// Stack structure for implementing a stack
typedef struct {
	int *data;
	int size;
	int top;
} stack;

// newStack initializes a new stack
stack *new_stack(int size) {
	stack *s = (stack *) malloc(sizeof(stack));
	s->data = (int *) malloc(size * sizeof(int));
	s->size = size;
	s->top = -1;
	return s;
}

// empty checks if the stack is empty
bool empty(stack *s) {
	return s->top == -1;
}

// full checks if the stack is full
bool full(stack *s) {
	return s->top == s->size - 1;
}

// push adds an element to the stack
void push(stack *s, int i) {
	if (full(s)) {
		return;
	}
	s->data[++s->top] = i;
}

// pop removes and returns the top element of the stack
int pop(stack *s) {
	if (empty(s)) {
		return 0;
	}
	return s->data[s->top--];
}

// priority_queue structure for implementing a max-heap
typedef struct {
	int *data;
	int size;
	int capacity;
} priority_queue;

// newPriorityQueue initializes a new priority queue
priority_queue *new_priority_queue(int capacity) {
	priority_queue *pq = (priority_queue *) malloc(sizeof(priority_queue));
	pq->data = (int *) malloc(capacity * sizeof(int));
	pq->size = 0;
	pq->capacity = capacity;
	return pq;
}

// empty checks if the priority queue is empty
bool empty(priority_queue *pq) {
	return pq->size == 0;
}

// full checks if the priority queue is full
bool full(priority_queue *pq) {
	return pq->size == pq->capacity;
}

// push adds an element to the priority queue
void push(priority_queue *pq, int i) {
	if (full(pq)) {
		return;
	}
	pq->data[pq->size] = i;
	pq->size++;
	int index = pq->size - 1;
	while (index > 0 && pq->data[index] > pq->data[(index - 1) / 2]) {
		int tmp = pq->data[index];
		pq->data[index] = pq->data[(index - 1) / 2];
		pq->data[(index - 1) / 2] = tmp;
		index = (index - 1) / 2;
	}
}

// pop removes and returns the top element of the priority queue
int pop(priority_queue *pq) {
	if (empty(pq)) {
		return 0;
	}
	int res = pq->data[0];
	pq->data[0] = pq->data[pq->size - 1];
	pq->size--;
	int index = 0;
	while (index < pq->size / 2) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int max = index;
		if (left < pq->size && pq->data[left] > pq->data[max]) {
			max = left;
		}
		if (right < pq->size && pq->data[right] > pq->data[max]) {
			max = right;
		}
		if (max!= index) {
			int tmp = pq->data[index];
			pq->data[index] = pq->data[max];
			pq->data[max] = tmp;
			index = max;
		} else {
			break;
		}
	}
	return res;
}

// sortable points structure for sorting points
typedef struct {
	int x;
	int y;
} point;

typedef struct {
	point *data;
	int size;
} points;

// Len returns the number of points
int len(points p) {
	return p.size;
}

// Less compares two points based on their x-coordinate
bool less(points p, int i, int j) {
	return p.data[i].x < p.data[j].x;
}

// Swap swaps two points in the slice
void swap(points p, int i, int j) {
	point tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

int main() {
	// Initialize a buffered reader to read input
	FILE *f = fopen("input.txt", "r");
	fseek(f, 0, SEEK_END);
	long lSize = ftell(f);
	rewind(f);
	char *buffer = (char *) malloc(sizeof(char) * lSize);
	fread(buffer, 1, lSize, f);
	fclose(f);
	char *pEnd;
	char *pStart = buffer;
	int n, m, R;
	n = strtol(pStart, &pEnd, 10);
	pStart = pEnd + 1;
	m = strtol(pStart, &pEnd, 10);
	pStart = pEnd + 1;
	R = strtol(pStart, &pEnd, 10);
	pStart = pEnd + 1;
	int *rs = (int *) malloc(R * sizeof(int));
	for (int i = 0; i < R; i++) {
		rs[i] = strtol(pStart, &pEnd, 10);
		pStart = pEnd + 1;
	}
	int **costs = (int **) malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		costs[i] = (int *) malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			costs[i][j] = INF;
		}
		costs[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		a = strtol(pStart, &pEnd, 10);
		pStart = pEnd + 1;
		b = strtol(pStart, &pEnd, 10);
		pStart = pEnd + 1;
		c = strtol(pStart, &pEnd, 10);
		pStart = pEnd + 1;
		costs[a - 1][b - 1] = c;
		costs[b - 1][a - 1] = c;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}
	int **perms = (int **) malloc(pow(R, 2) * sizeof(int *));
	for (int i = 0; i < pow(R, 2); i++) {
		perms[i] = (int *) malloc(R * sizeof(int));
	}
	int **perms_tmp = (int **) malloc(R * sizeof(int *));
	for (int i = 0; i < R; i++) {
		perms_tmp[i] = (int *) malloc(R * sizeof(int));
	}
	int **perms_tmp2 = (int **) malloc(R * sizeof(int 