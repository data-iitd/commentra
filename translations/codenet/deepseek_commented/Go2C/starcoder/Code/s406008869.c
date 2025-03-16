
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int **e = (int **)malloc(sizeof(int *) * (n+1));
	for (int i = 1; i < n+1; i++) {
		e[i] = (int *)malloc(sizeof(int) * 0);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a] = (int *)realloc(e[a], sizeof(int) * (sizeof(int) * (i+1)));
		e[a][i] = b;
		e[b] = (int *)realloc(e[b], sizeof(int) * (sizeof(int) * (i+1)));
		e[b][i] = a;
	}

	int *visited = (int *)malloc(sizeof(int) * (n+1));
	for (int i = 1; i < n+1; i++) {
		visited[i] = 0;
	}
	visited[1] = 1;
	int count = dfs(1, visited, e);
	printf("%d\n", count);
}

int dfs(int v, int *visited, int **e) {
	int count = 0;
	for (int i = 0; i < sizeof(e[v])/sizeof(int); i++) {
		int ne = e[v][i];
		if (visited[ne]) {
			continue;
		}
		visited[ne] = 1;
		count += dfs(ne, visited, e);
		visited[ne] = 0;
	}
	return count;
}

