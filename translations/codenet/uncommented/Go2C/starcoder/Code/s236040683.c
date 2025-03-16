#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int to[100000];
} Node;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	Node *n = (Node*)malloc(sizeof(Node) * N);
	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		n[from].to[n[from].to_num++] = to;
		n[to].to[n[to].to_num++] = from;
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", n[i].to_num);
	}
	return 0;
}

