#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Constants MOD and INF for modular arithmetic and infinite values.
#define MOD 1000000007
#define INF 1000000000000000000

// Custom type RuneSlice to implement sort.Interface for sorting rune slices.
typedef struct {
	size_t len;
	rune *arr;
} RuneSlice;

// Mon struct and Mons type for monsters.
typedef struct {
	int x, h;
} Mon;

typedef Mon *Mons;

// Queue struct to manage a queue of nodes.
// Methods include pushing, popping, and checking if the queue is empty.
typedef struct {
	size_t len;
	Mon *arr;
} Queue;

// Scanner struct to read input efficiently.
// Methods include reading strings, integers, floats, rune slices, and slices of integers and floats.
typedef struct {
	char *s;
	size_t pos;
	size_t len;
} Scanner;

// NewScanner returns a new Scanner reading from os.Stdin.
Scanner NewScanner() {
	Scanner sc;
	sc.s = NULL;
	sc.pos = 0;
	sc.len = 0;
	return sc;
}

// InitScanner initializes a Scanner to read from s.
void InitScanner(Scanner *sc, char *s) {
	sc->s = s;
	sc->pos = 0;
	sc->len = strlen(s);
}

// NextStr returns the next string.
char* NextStr(Scanner *sc) {
	char *res = malloc(1024);
	char *c = res;
	while (sc->pos < sc->len &&!isspace(sc->s[sc->pos])) {
		*c = sc->s[sc->pos];
		c++;
		sc->pos++;
	}
	*c = '\0';
	return res;
}

// NextInt returns the next integer.
int NextInt(Scanner *sc) {
	int res = 0;
	bool neg = false;
	if (sc->s[sc->pos] == '-') {
		neg = true;
		sc->pos++;
	}
	while (sc->pos < sc->len && isdigit(sc->s[sc->pos])) {
		res = res*10 + sc->s[sc->pos]-'0';
		sc->pos++;
	}
	if (neg) {
		res = -res;
	}
	return res;
}

// NextFloat returns the next float.
float NextFloat(Scanner *sc) {
	float res = 0;
	bool neg = false;
	if (sc->s[sc->pos] == '-') {
		neg = true;
		sc->pos++;
	}
	while (sc->pos < sc->len && isdigit(sc->s[sc->pos])) {
		res = res*10 + sc->s[sc->pos]-'0';
		sc->pos++;
	}
	if (sc->pos < sc->len && sc->s[sc->pos] == '.') {
		sc->pos++;
		float p = 1;
		while (sc->pos < sc->len && isdigit(sc->s[sc->pos])) {
			res += (sc->s[sc->pos]-'0') / (float)pow(10, p);
			p *= 10;
			sc->pos++;
		}
	}
	if (neg) {
		res = -res;
	}
	return res;
}

// NextRuneSlice returns the next rune slice.
RuneSlice NextRuneSlice(Scanner *sc) {
	RuneSlice res;
	res.len = 0;
	res.arr = NULL;
	while (sc->pos < sc->len &&!isspace(sc->s[sc->pos])) {
		res.arr = realloc(res.arr, sizeof(rune)*(res.len+1));
		res.arr[res.len] = sc->s[sc->pos];
		res.len++;
		sc->pos++;
	}
	return res;
}

// NextIntSlice returns the next int slice.
int* NextIntSlice(Scanner *sc, int n) {
	int *res = malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		res[i] = NextInt(sc);
	}
	return res;
}

// NextFloatSlice returns the next float slice.
float* NextFloatSlice(Scanner *sc, int n) {
	float *res = malloc(sizeof(float)*n);
	for (int i = 0; i < n; i++) {
		res[i] = NextFloat(sc);
	}
	return res;
}

// max returns the maximum of the given integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the minimum of the given integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// abs returns the absolute value of the given integer.
int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// pow returns the power of the given integers.
int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// ceil returns the ceiling of the given integers.
int ceil(int a, int b) {
	if (a%b == 0) {
		return a/b;
	} else {
		return a/b + 1;
	}
}

// Custom type RuneSlice to implement sort.Interface for sorting rune slices.
RuneSlice NewRuneSlice(int n) {
	RuneSlice res;
	res.len = n;
	res.arr = malloc(sizeof(rune)*n);
	return res;
}

void FreeRuneSlice(RuneSlice *rs) {
	free(rs->arr);
}

// Constants MOD and INF for modular arithmetic and infinite values.
#define MOD 1000000007
#define INF 1000000000000000000

// Mon struct and Mons type for monsters.
typedef struct {
	int x, h;
} Mon;

typedef Mon *Mons;

// Queue struct to manage a queue of nodes.
// Methods include pushing, popping, and checking if the queue is empty.
typedef struct {
	size_t len;
	Mon *arr;
} Queue;

// NewQueue returns a new Queue.
Queue NewQueue() {
	Queue q;
	q.len = 0;
	q.arr = NULL;
	return q;
}

// FreeQueue frees the memory of the given Queue.
void FreeQueue(Queue *q) {
	free(q->arr);
}

// push pushes the given Node to the given Queue.
void push(Queue *q, Mon v) {
	q->arr = realloc(q->arr, sizeof(Mon)*(q->len+1));
	q->arr[q->len] = v;
	q->len++;
}

// first returns the first Node of the given Queue.
Mon first(Queue *q) {
	return q->arr[0];
}

// pop pops the first Node of the given Queue.
Mon pop(Queue *q) {
	Mon res = q->arr[0];
	q->arr = realloc(q->arr, sizeof(Mon)*(q->len-1));
	q->len--;
	return res;
}

// isEmpty returns true if the given Queue is empty.
bool isEmpty(Queue *q) {
	return q->len == 0;
}

// SortMons sorts the given Mons.
void SortMons(Mons mons, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (mons[i].x > mons[j].x) {
				Mon tmp = mons[i];
				mons[i] = mons[j];
				mons[j] = tmp;
			}
		}
	}
}

// main function
int main(int argc, char *argv[]) {
	Scanner sc = NewScanner();
	InitScanner(&sc, argv[1]);
	int N = NextInt(&sc);
	int D = NextInt(&sc);
	int A = NextInt(&sc);
	Mons M = malloc(sizeof(Mon)*N);
	for (int i = 0; i < N; i++) {
		M[i].x = NextInt(&sc);
		M[i].h = NextInt(&sc);
	}
	SortMons(M, N);
	Queue q = NewQueue();
	int ans = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		Mon m = M[i];
		while (!isEmpty(&q) && first(&q).x < m.x) {
			total -= pop(&q).h;
		}
		if (total < m.h) {
			m.h -= total;
			int count = ceil(m.h, A);
			ans += count;
			int damage = count * A;
			push(&q, (Mon){m.x + 2*D, damage});
			total += damage;
		}
	}
	printf("%d\n", ans);
	return 0;
}

