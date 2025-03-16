

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// I/O
// Scanner struct to handle input reading
typedef struct {
	char *p, *pe, *eof;
	int len;
} Scanner;

// NewScanner initializes a new Scanner for reading input
Scanner newScanner(char *buf, int len) {
	Scanner sc;
	sc.p = buf;
	sc.pe = buf + len;
	sc.eof = buf + len;
	sc.len = len;
	return sc;
}

// nextStr reads the next string from input
char *nextStr(Scanner *sc) {
	while (*sc->p =='' || *sc->p == '\n' || *sc->p == '\t' || *sc->p == '\r') {
		sc->p++;
	}
	char *p = sc->p;
	while (*sc->p!='' && *sc->p!= '\n' && *sc->p!= '\t' && *sc->p!= '\r' && sc->p < sc->eof) {
		sc->p++;
	}
	int len = sc->p - p;
	char *res = malloc(len + 1);
	memcpy(res, p, len);
	res[len] = '\0';
	return res;
}

// nextInt reads the next integer from input
int nextInt(Scanner *sc) {
	char *p = nextStr(sc);
	int res = atoi(p);
	free(p);
	return res;
}

// nextFloat reads the next float from input
double nextFloat(Scanner *sc) {
	char *p = nextStr(sc);
	double res = atof(p);
	free(p);
	return res;
}

// max returns the maximum value from a list of integers
int max(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		if (res < nums[i]) {
			res = nums[i];
		}
	}
	return res;
}

// min returns the minimum value from a list of integers
int min(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		if (res > nums[i]) {
			res = nums[i];
		}
	}
	return res;
}

// abs returns the absolute value of an integer
int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// pow calculates x raised to the power of y
int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// ceil calculates the ceiling of a/b
int ceil(int a, int b) {
	if (a % b == 0) {
		return a / b;
	} else {
		return a / b + 1;
	}
}

// Sort
// RuneSlice is a type that implements sort.Interface for slices of runes
typedef struct {
	int len;
	rune *arr;
} RuneSlice;

int runeSliceLen(RuneSlice a) {
	return a.len;
}

int runeSliceLess(RuneSlice a, int i, int j) {
	return a.arr[i] < a.arr[j];
}

void runeSliceSwap(RuneSlice a, int i, int j) {
	rune tmp = a.arr[i];
	a.arr[i] = a.arr[j];
	a.arr[j] = tmp;
}

// Main
#define MOD 1000000007
#define INF 1000000000

// Mon represents a monster with position x and health h
typedef struct {
	int x, h;
} Mon;

// Mons is a slice of Mon for sorting
typedef struct {
	int len;
	Mon *arr;
} Mons;

int monsLen(Mons a) {
	return a.len;
}

int monsLess(Mons a, int i, int j) {
	return a.arr[i].x < a.arr[j].x;
}

void monsSwap(Mons a, int i, int j) {
	Mon tmp = a.arr[i];
	a.arr[i] = a.arr[j];
	a.arr[j] = tmp;
}

// Node represents a position and damage
typedef struct {
	int x, h;
} Node;

// Queue is a simple queue implementation for Nodes
typedef struct {
	int len;
	Node *arr;
} Queue;

// push adds a Node to the end of the queue
void queuePush(Queue *q, Node v) {
	q->arr[q->len++] = v;
}

// first returns the first Node in the queue without removing it
Node queueFirst(Queue *q) {
	return q->arr[0];
}

// pop removes and returns the first Node in the queue
Node queuePop(Queue *q) {
	Node res = q->arr[0];
	q->arr[0] = q->arr[--q->len];
	return res;
}

// isEmpty checks if the queue is empty
int queueIsEmpty(Queue *q) {
	return q->len == 0;
}

int main() {
	Scanner sc = newScanner(stdin, 1024); // Initialize the scanner for input
	int N = nextInt(&sc); // Read N
	int D = nextInt(&sc); // Read D
	int A = nextInt(&sc); // Read A
	Mons M = {N, malloc(sizeof(Mon) * N)}; // Create a slice to hold monsters
	for (int i = 0; i < N; i++) {
		M.arr[i].x = nextInt(&sc); // Read each monster's position
		M.arr[i].h = nextInt(&sc); // Read each monster's health
	}
	qsort(M.arr, N, sizeof(Mon), (int (*)(const void *, const void *))monsLess); // Sort monsters by their position

	Queue q = {0, malloc(sizeof(Node) * N)}; // Initialize a queue to manage damage
	int ans = 0; // Variable to count the total number of attacks
	int total = 0; // Variable to track total damage dealt

	// Iterate through each monster
	for (int i = 0; i < N; i++) {
		Mon m = M.arr[i]; // Get the current monster
		// Remove monsters from the queue that are out of range
		while (!queueIsEmpty(&q) && queueFirst(&q).x < m.x) {
			total -= queuePop(&q).h; // Decrease total damage by the damage of the popped monster
		}
		// If the total damage is less than the monster's health
		if (total < m.h) {
			m.h -= total; // Reduce the monster's health by total damage
			int count = ceil(m.h, A); // Calculate how many attacks are needed
			ans += count; // Increment the total attack count
			int damage = count * A; // Calculate the total damage dealt to this monster
			queuePush(&q, (Node){m.x + 2 * D, damage}); // Add the monster's damage to the queue
			total += damage; // Update the total damage
		}
	}

	printf("%d\n", ans); // Output the total number of attacks
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// I/O
// Scanner struct to handle input reading
typedef struct {
	char *p, *pe, *eof;
	int len;
} Scanner;

// NewScanner initializes a new Scanner for reading input
Scanner newScanner(char *buf, int len) {
	Scanner sc;
	sc.p = buf;
	sc.pe = buf + len;
	sc.eof = buf + len;
	sc.len = len;
	return sc;
}

// nextStr reads the next string from input
char *nextStr(Scanner *sc) {
	while (*sc->p =='' || *sc->p == '\n' || *sc->p == '\t' || *sc->p == '\r') {
		sc->p++;
	}
	char *p = sc->p;
	while (*sc->p!='' && *sc->p!= '\n' && *sc->p!= '\t' && *sc->p!= '\r' && sc->p < sc->eof) {
		sc->p++;
	}
	int len = sc->p - p;
	char *res = malloc(len + 1);
	memcpy(res, p, len);
	res[len] = '\0';
	return res;
}

// nextInt reads the next integer from input
int nextInt(Scanner *sc) {
	char *p = nextStr(sc);
	int res = atoi(p);
	free(p);
	return res;
}

// nextFloat reads the next float from input
double nextFloat(Scanner *sc) {
	char *p = nextStr(sc);
	double res = atof(p);
	free(p);
	return res;
}

// max returns the maximum value from a list of integers
int max(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		if (res < nums[i]) {
			res = nums[i];
		}
	}
	return res;
}

// min returns the minimum value from a list of integers
int min(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		if (res > nums[i]) {
			res = nums[i];
		}
	}
	return res;
}

// abs returns the absolute value of an integer
int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// pow calculates x raised to the power of y
int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// ceil calculates the ceiling of a/b
int ceil(int a, int b) {
	if (a % b == 0) {
		return a / b;
	} else {
		return a / b + 1;
	}
}

// Sort
// RuneSlice is a type that implements sort.Interface for slices of runes
typedef struct {
	int len;
	rune *arr;
} RuneSlice;

int runeSliceLen(RuneSlice a) {
	return a.len;
}

int runeSliceLess(RuneSlice a, int i, int j) {
	return a.arr[i] < a.arr[j];
}

void runeSliceSwap(RuneSlice a, int i, int j) {
	rune tmp = a.arr[i];
	a.arr[i] = a.arr[j];
	a.arr[j] = tmp;
}

// Main
#define MOD 1000000007
#define INF 1000000000

// Mon represents a monster with position x and health h
typedef struct {
	int x, h;
} Mon;

// Mons is a slice of Mon for sorting
typedef struct {
	int len;
	Mon *arr;
} Mons;

int monsLen(Mons a) {
	return a.len;
}

int monsLess(Mons a, int i, int j) {
	return a.arr[i].x < a.arr[j].x;
}

void monsSwap(Mons a, int i, int j) {
	Mon tmp = a.arr[i];
	a.arr[i] = a.arr[j];
	a.arr[j] = tmp;
}

// Node represents a position and damage
typedef struct {
	int x, h;
} Node;

// Queue is a simple queue implementation for Nodes
typedef struct {
	int len;
	Node *arr;
} Queue;

// push adds a Node to the end of the queue
void queuePush(Queue *q, Node v) {
	q->arr[q->len++] = v;
}

// first returns the first Node in the queue without removing it
Node queueFirst(Queue *q) {
	return q->arr[0];
}

// pop removes and returns the first Node in the queue
Node queuePop(Queue *q) {
	Node res = q->arr[0];
	q->arr[0] = q->arr[--q->len];
	return res;
}

// isEmpty checks if the queue is empty
int queueIsEmpty(Queue *q) {
	return q->len == 0;
}

int main() {
	Scanner sc = newScanner(stdin, 1024); // Initialize the scanner for input
	int N = nextInt(&sc); // Read N
	int D = nextInt(&sc); // Read D
	int A = nextInt(&sc); // Read A
	Mons M = {N, malloc(sizeof(Mon) * N)}; // Create a slice to hold monsters
	for (int i = 0; i < N; i++) {
		M.arr[i].x = nextInt(&sc); // Read each monster's position
		M.arr[i].h = nextInt(&sc); // Read each monster's health
	}
	qsort(M.arr, N, sizeof(Mon), (int (*)(const void *, const void *))monsLess); // Sort monsters by their position

	Queue q = {0, malloc(sizeof(Node) * N)}; // Initialize a queue to manage damage
	int ans = 0; // Variable to count the total number of attacks
	int total = 0; // Variable to track total damage dealt

	// Iterate through each monster
	for (int i = 0; i < N; i++) {
		Mon m = M.arr[i]; // Get the current monster
		// Remove monsters from the queue that are out of range
		while (!queueIsEmpty(&q) && queueFirst(&q).x < m.x) {
			total -= queuePop(&q).h; // Decrease total damage by the damage of the popped monster
		}
		// If the total damage is less than the monster's health
		if (total < m.h) {
			m.h -= total; // Reduce the monster's health by total damage
			int count = ceil(m.h, A); // Calculate how many attacks are needed
			ans += count; // Increment the total attack count
			int damage = count * A; // Calculate the total damage dealt to this monster
			queuePush(&q, (Node){m.x + 2 * D, damage}); // Add the monster's damage to the queue
			total += damage; // Update the total damage
		}
	}

	printf("%d\n", ans); // Output the total number of attacks
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// I/O
// Scanner struct to handle input r