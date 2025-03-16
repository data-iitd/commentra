#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define out(x...) printf(x)

int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

char *getString() {
	char *s = malloc(100);
	scanf("%s", s);
	return s;
}

typedef struct {
	int *to;
} Node;

int main() {
	int N, M;
	N = getInt();
	M = getInt();
	Node *n = malloc(N * sizeof(Node));
	for (int i = 0; i < M; i++) {
		int from, to;
		from = getInt() - 1;
		to = getInt() - 1;
		n[from].to = realloc(n[from].to, (i + 1) * sizeof(int));
		n[from].to[i] = to;
		n[to].to = realloc(n[to].to, (i + 1) * sizeof(int));
		n[to].to[i] = from;
	}

	for (int i = 0; i < N; i++) {
		out("%d\n", sizeof(n[i].to) / sizeof(int));
	}

	return 0;
}

