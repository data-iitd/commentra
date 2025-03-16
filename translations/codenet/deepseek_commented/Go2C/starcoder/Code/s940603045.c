#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

// const abcd = "abcdefghijklmnopqrstuvwxyz"
// const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
const int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dy[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

const int inf = INT_MAX;

// var mod = 1000000007

// var next = newScanner();

// ---------------------------------------------------------
// Initializes logging and random number generator seed
void init() {
	// log.SetFlags(log.Lshortfile)
	// rand.Seed(time.Now().UnixNano())
}

// Main function reads a string, calculates digit sum, and checks divisibility
int main() {
	char *N = next.String(); // Read input string
	char *b = malloc(sizeof(char) * strlen(N));
	strcpy(b, N);
	int n = 0; // Initialize sum of digits

	// Calculate sum of digits
	for (int i = 0; i < strlen(b); i++) {
		n += (int)(b[i] - '0');
	}
	int m = atoi(N); // Convert input string to integer
	if (m % n == 0) { // Check if the number is divisible by the sum of its digits
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

// ---------------------------------------------------------

// Pair is a struct representing a pair of integers
typedef struct {
	int a, b;
} Pair;

// Pairs is a slice of Pair structs, implementing sort.Interface
typedef struct {
	Pair *data;
	int len;
} Pairs;

int Pairs_Len(Pairs *p) {
	return p->len;
}
void Pairs_Swap(Pairs *p, int i, int j) {
	Pair tmp = p->data[i];
	p->data[i] = p->data[j];
	p->data[j] = tmp;
}
bool Pairs_Less(Pairs *p, int i, int j) {
	return p->data[i].b < p->data[j].b;
}

// ------int method-------------------------
bool in(int c, int a, int z) {
	return c >= a && c < z;
}
bool out(int c, int a, int z) {
	return!in(c, a, z);
}
int btoi(bool b) {
	if (b) {
		return 1;
	}
	return 0;
}
bool itob(int a) {
	return a!= 0;
}
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}
int sum(int *a, int n) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		r += a[i];
	}
	return r;
}
int pro(int *a, int n) {
	int r = 1;
	for (int i = 0; i < n; i++) {
		r *= a[i];
	}
	return r;
}

int *fill(int *a, int n, int v) {
	for (int i = 0; i < n; i++) {
		a[i] = v;
	}
	return a;
}
int minmax(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

//
//int abs(int a) {
//	int mask = a >> 63
//	return (a ^ mask) - mask
//}

int ceil(int a, int b) {
	if (a % b!= 0) {
		return 1;
	}
	return 0;
}

void printStrings(char **out, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s", out[i]);
		if (i!= n-1) {
			printf(" ");
		}
	}
	printf("\n");
}
void printInts(int *out, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", out[i]);
		if (i!= n-1) {
			printf(" ");
		}
	}
	printf("\n");
}

// ---------- buffered scanner -----------------------------------------
typedef struct {
	FILE *f;
	char buf[10000];
	int p;
} scanner;

scanner newScanner() {
	scanner s;
	s.f = stdin;
	s.p = 0;
	return s;
}
char *next(scanner *s) {
	s->pre();
	char *start = s->p;
	while (s->p < strlen(s->buf)) {
		if (s->buf[s->p] =='') {
			break;
		}
		s->p++;
	}
	char *result = malloc(sizeof(char) * (s->p - start + 1));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}
char *Line(scanner *s) {
	s->pre();
	char *start = s->p;
	s->p = strlen(s->buf);
	char *result = malloc(sizeof(char) * (s->p - start + 1));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}
char *String(scanner *s) {
	return next(s);
}
int Int(scanner *s) {
	char *v = next(s);
	int result = atoi(v);
	free(v);
	return result;
}
int *Ints(scanner *s, int n) {
	int *r = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		r[i] = Int(s);
	}
	return r;
}
int64_t Int64(scanner *s) {
	char *v = next(s);
	int64_t result = atoll(v);
	free(v);
	return result;
}
uint64_t Uint64(scanner *s) {
	char *v = next(s);
	uint64_t result = atoll(v);
	free(v);
	return result;
}
double Float64(scanner *s) {
	char *v = next(s);
	double result = atof(v);
	free(v);
	return result;
}
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) {
		s->readLine();
		s->p = 0;
	}
}
void readLine(scanner *s) {
	s->buf[0] = '\0';
	fgets(s->buf, 10000, s->f);
}

