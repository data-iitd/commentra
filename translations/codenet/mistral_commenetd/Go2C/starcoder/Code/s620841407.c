
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP3(i, m, n) for (int i = (m); i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	int **edges = (int **)malloc(sizeof(int *) * n);
	REP(i, n) {
		edges[i] = (int *)malloc(sizeof(int) * n);
		REP(j, n) {
			edges[i][j] = 0;
		}
	}
	REP(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		edges[x][y] = 1;
		edges[y][x] = 1;
	}

	int *parents = (int *)malloc(sizeof(int) * n);
	int *order = (int *)malloc(sizeof(int) * n);

	// InitOrderedTree
	int index = 0;
	int *stack = (int *)malloc(sizeof(int) * n);
	int stack_top = 0;
	stack[stack_top] = 0;
	parents[0] = -1;
	while (stack_top >= 0) {
		int node = stack[stack_top];
		stack_top--;
		order[index] = node;
		index++;
		for (int i = 0; i < n; i++) {
			int adjacent = edges[node][i];
			if (adjacent == parents[node]) {
				continue;
			}
			stack[stack_top] = adjacent;
			stack_top++;
			parents[adjacent] = node;
		}
	}

	// fromLeaf
	for (int i = n - 1; i >= 1; i--) {
		int node = order[i];
		int parent = parents[node];

		int accum = 0;
		int parentIndex = -1;
		for (int j = 0; j < n; j++) {
			if (edges[node][j] == parent) {
				parentIndex = j;
				continue;
			}
			accum = accum * 1000000007 + s[node][j];
		}
		s[parent][parentIndex] = accum;
		accum = accum * 1000000007 + s[node][j];
		s[node][j] = accum;
	}

	// toLeaf
	for (int i = 0; i < n; i++) {
		int node = order[i];
		int accum = 0;
		int *accumsFromTail = (int *)malloc(sizeof(int) * n);
		accumsFromTail[n - 1] = 0;
		for (int j = n - 1; j >= 1; j--) {
			accumsFromTail[j - 1] = accumsFromTail[j] * 1000000007 + s[node][j];
		}
		for (int j = 0; j < n; j++) {
			s[edges[node][j]][edges[node][j]] = accum * 1000000007 + accumsFromTail[j];
			accum = accum * 1000000007 + s[node][j];
		}
		printf("%d\n", accum);
	}

	return 0;
}

