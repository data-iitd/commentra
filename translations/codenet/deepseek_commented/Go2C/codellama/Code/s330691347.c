#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// out is a utility function to print multiple values with a newline.
void out(int x, int y, char *z) {
	//	printf("%d %d %s\n", x, y, z);
}

// sc is a global Scanner to read input.
FILE *sc;

// nextInt reads an integer from the input.
int nextInt() {
	char *p;
	int i;
	sc = fopen("input.txt", "r");
	fscanf(sc, "%d", &i);
	fclose(sc);
	return i;
}

// nextString reads a string from the input.
char *nextString() {
	char *p;
	int i;
	sc = fopen("input.txt", "r");
	fscanf(sc, "%s", &p);
	fclose(sc);
	return p;
}

// Data represents a structure holding a string.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data structures.
typedef struct {
	Data *p;
	int len;
} Datas;

// Len returns the length of the Datas slice.
int Len(Datas *p) {
	return p->len;
}

// Swap swaps the elements at indices i and j.
void Swap(Datas *p, int i, int j) {
	Data temp = p->p[i];
	p->p[i] = p->p[j];
	p->p[j] = temp;
}

// Less returns true if the element at index i is less than the element at index j.
int Less(Datas *p, int i, int j) {
	return strcmp(p->p[i].X, p->p[j].X) < 0;
}

// The main function reads N strings, sorts them, and prints the concatenated result.
int main() {
	int N, L;
	char *p;
	Datas s;

	N = nextInt();
	L = nextInt();
	s.p = (Data *)malloc(N * sizeof(Data));
	s.len = N;

	for (int i = 0; i < N; i++) {
		s.p[i].X = nextString();
	}

	out(N, L, s.p[0].X);
	qsort(s.p, s.len, sizeof(Data), (int (*)(const void *, const void *))Less);
	out(s.p);

	char *ans = (char *)malloc(N * sizeof(char));
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.p[i].X);
	}
	printf("%s\n", ans);

	return 0;
}

