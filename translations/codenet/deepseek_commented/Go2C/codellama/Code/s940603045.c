
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// const abcd = "abcdefghijklmnopqrstuvwxyz"
// const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

int inf = 2147483647;

// var mod = 1000000007

// ---------------------------------------------------------
// Initializes logging and random number generator seed
void init() {
	log.SetFlags(log.Lshortfile);
	rand.Seed(time.Now().UnixNano());
}

// Main function reads a string, calculates digit sum, and checks divisibility
void main() {
	char N[100]; // Read input string
	int b[100]; // Convert string to byte slice
	int n = 0; // Initialize sum of digits

	// Calculate sum of digits
	for (int i = 0; i < 100; i++) {
		n += b[i] - '0';
	}
	int m, _ = strconv.Atoi(N); // Convert input string to integer
	if (m%n == 0) { // Check if the number is divisible by the sum of its digits
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
	int len;
	Pair *pairs;
} Pairs;

int Pairs_Len(Pairs *p) {
	return p->len;
}
void Pairs_Swap(Pairs *p, int i, int j) {
	Pair tmp = p->pairs[i];
	p->pairs[i] = p->pairs[j];
	p->pairs[j] = tmp;
}

int Pairs_Less(Pairs *p, int i, int j) {
	return p->pairs[i].b < p->pairs[j].b;
}

// ------int method-------------------------
int in(int c, int a, int z) {
	return c >= a && c < z;
}
int out(int c, int a, int z) {
	return !in(c, a, z);
}
int btoi(int b) {
	if (b) {
		return 1;
	}
	return 0;
}
int itob(int a) {
	return a != 0;
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
int sum(int a[], int n) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		r += a[i];
	}
	return r;
}
int pro(int a[], int n) {
	int r = a[0];
	for (int i = 1; i < n; i++) {
		r *= a[i];
	}
	return r;
}

int *fill(int a[], int n, int v) {
	for (int i = 0; i < n; i++) {
		a[i] = v;
	}
	return a;
}
int minmax(int a, int b) {
	if (a > b) {
		return b, a;
	}
	return a, b;
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

//
//int abs(int a) {
//	int mask = a >> 63;
//	return (a ^ mask) - mask;
//}

int ceil(int a, int b) {
	if (a%b != 0) {
		return 1;
	}
	return 0;
}

void printStrings(char *out[]) {
	for (int i = 0; i < 100; i++) {
		printf(out[i]);
		if (i != 99) {
			printf(" ");
		}
	}
	printf("\n");
}
void printInts(int out[]) {
	for (int i = 0; i < 100; i++) {
		printf(out[i]);
		if (i != 99) {
			printf(" ");
		}
	}
	printf("\n");
}

// ---------- buffered scanner -----------------------------------------
typedef struct {
	FILE *r;
	char buf[10000];
	int p;
} scanner;

scanner *newScanner() {
	FILE *rdr = fopen("stdin", "r");
	return &scanner{r: rdr};
}
char *next(scanner *s) {
	s->pre();
	int start = s->p;
	for (; s->p < 10000; s->p++) {
		if (s->buf[s->p] == ' ') {
			break;
		}
	}
	char *result = s->buf[start:s->p];
	s->p++;
	return result;
}
char *Line(scanner *s) {
	s->pre();
	int start = s->p;
	s->p = 10000;
	return s->buf[start:];
}
char *String(scanner *s) {
	return s->next();
}
int Int(scanner *s) {
	int v, err = strconv.Atoi(s->next());
	if (err != 0) {
		log.Fatal(err);
	}
	return v;
}
int *Ints(scanner *s, int n) {
	int r[100];
	for (int i = 0; i < 100; i++) {
		r[i] = s->Int();
	}
	return r;
}
int Int64(scanner *s) {
	int v, err = strconv.ParseInt(s->next(), 10, 64);
	if (err != 0) {
		log.Fatal(err);
	}
	return v;
}
int Uint64(scanner *s) {
	int v, err = strconv.ParseUint(s->next(), 10, 64);
	if (err != 0) {
		log.Fatal(err);
	}
	return v;
}
int Float64(scanner *s) {
	int v, err = strconv.ParseFloat(s->next(), 64);
	if (err != 0) {
		log.Fatal(err);
	}
	return v;
}
void pre(scanner *s) {
	if (s->p >= 10000) {
		s->readLine();
		s->p = 0;
	}
}
void readLine(scanner *s) {
	s->buf = "";
	for (;;) {
		char l[10000];
		int p, err = fgets(l, 10000, s->r);
		if (err != 0) {
			log.Fatal(err);
		}
		s->buf += l;
		if (!p) {
			break;
		}
	}
}

