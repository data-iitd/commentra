
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

typedef struct Node {
	int to[MAX_N];
} Node;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	Node n[MAX_N];
	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		n[from].to[n[from].to_size++] = to;
		n[to].to[n[to].to_size++] = from;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", n[i].to_size);
	}
}

