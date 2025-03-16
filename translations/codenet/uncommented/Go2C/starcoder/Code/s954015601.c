#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
	int a;
	int b;
} edge;

int N;
edge edges[MAX_M];
int colors[MAX_M];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		edges[i].a = a;
		edges[i].b = b;
	}

	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = 0;
		for (int j = 0; j < N; j++) {
			t += (edges[j].a == i || edges[j].b == i);
		}
		if (t > K) {
			K = t;
		}
	}
	printf("%d\n", K);

	for (int i = 0; i < N-1; i++) {
		int a = edges[i].a;
		int b = edges[i].b;
		int c = (a > b)? a*100000 + b : b*100000 + a;
		printf("%d\n", colors[c]);
	}
}

