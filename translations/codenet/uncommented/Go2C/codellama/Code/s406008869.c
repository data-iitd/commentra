#include <stdio.h>
#include <stdlib.h>

int n, m;
int **e;

void printEdge(int **e) {
	for (int i = 1; i < n+1; i++) {
		printf("%d: ", i);
		for (int j = 0; j < e[i][0]; j++) {
			printf("%d ", e[i][j+1]);
		}
		printf("\n");
	}
}

int dfs(int v, int *visited) {
	// visited[v] = true
	// printf("%d, ", v);

	int comp = 1;
	for (int i = 1; i < n+1; i++) {
		if (!visited[i]) {
			comp = 0;
		}
	}

	if (comp) {
		return 1;
	}

	int count = 0;
	for (int i = 1; i < e[v][0]; i++) {
		// printf("ne=%d\n", e[v][i]);
		if (visited[e[v][i]]) {
			continue;
		}
		visited[e[v][i]] = 1;
		// if (cmp, _ := dfs(e[v][i], visited, count); cmp) {
		// 	count++;
		// }
		count += dfs(e[v][i], visited);
		visited[e[v][i]] = 0;
	}
	return count;
}

int main() {
	scanf("%d %d", &n, &m);

	e = (int **)malloc((n+1) * sizeof(int *));
	for (int i = 1; i < n+1; i++) {
		e[i] = (int *)malloc((m+1) * sizeof(int));
		e[i][0] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a][0]++;
		e[a][e[a][0]] = b;
		e[b][0]++;
		e[b][e[b][0]] = a;
	}
	// printEdge(e);

	int *visited = (int *)malloc((n+1) * sizeof(int));
	for (int i = 1; i < n+1; i++) {
		visited[i] = 0;
	}
	visited[1] = 1;
	int count = dfs(1, visited);
	printf("%d\n", count);

	return 0;
}

