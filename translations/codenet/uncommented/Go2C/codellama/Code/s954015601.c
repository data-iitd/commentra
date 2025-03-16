// 深さ優先探索
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int genid(int a, int b) {
	if (b < a) {
		a = b;
		b = a;
	}
	return a*100000 + b;
}

int main() {
	int N;
	scanf("%d", &N);

	int ab[N-1][2];
	int *edges[N];
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &ab[i][0], &ab[i][1]);
		ab[i][0]--;
		ab[i][1]--;
		edges[ab[i][0]] = (int *)realloc(edges[ab[i][0]], sizeof(int) * (edges[ab[i][0]] ? strlen(edges[ab[i][0]]) : 0) + sizeof(int));
		edges[ab[i][0]][strlen(edges[ab[i][0]])/sizeof(int)] = ab[i][1];
		edges[ab[i][1]] = (int *)realloc(edges[ab[i][1]], sizeof(int) * (edges[ab[i][1]] ? strlen(edges[ab[i][1]]) : 0) + sizeof(int));
		edges[ab[i][1]][strlen(edges[ab[i][1]])/sizeof(int)] = ab[i][0];
	}

	int colors[N];
	int q[N][3];
	q[0][0] = 0;
	q[0][1] = -1;
	q[0][2] = -1;
	int q_size = 1;
	for (int i = 0; i < N; i++) {
		colors[i] = 0;
	}
	while (q_size != 0) {
		int currentNode = q[q_size-1][0];
		int usedColor = q[q_size-1][1];
		int parentNode = q[q_size-1][2];
		q_size--;
		int color = 1;
		for (int i = 0; i < strlen(edges[currentNode])/sizeof(int); i++) {
			int childNode = edges[currentNode][i];
			if (childNode == parentNode) {
				continue;
			}
			if (color == usedColor) {
				color++;
			}
			colors[genid(currentNode, childNode)] = color;
			q[q_size][0] = childNode;
			q[q_size][1] = color;
			q[q_size][2] = currentNode;
			q_size++;
			color++;
		}
	}

	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = strlen(edges[i])/sizeof(int);
		if (t > K) {
			K = t;
		}
	}
	printf("%d\n", K);

	for (int i = 0; i < N-1; i++) {
		printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
	}
	return 0;
}

