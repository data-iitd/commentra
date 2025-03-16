#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000007

int min(int a, int b) {
	return a < b ? a : b;
}

int** floyd_warshall(int** costs, int n) {
	int** dist = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		dist[i] = malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			dist[i][j] = costs[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	return dist;
}

int** permutations(int* arr, int n) {
	int** res = malloc(n * sizeof(int*));
	int i, j, k;
	for (i = 0; i < n; i++) {
		res[i] = malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			res[i][j] = arr[j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j) {
				k = res[i][j];
				res[i][j] = res[i][n-1];
				res[i][n-1] = k;
			}
		}
	}
	return res;
}

int main() {
	int n, m, R, a, b, c, i, j, k, tmp, ans;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &R);
	int* rs = malloc(R * sizeof(int));
	for (i = 0; i < R; i++) {
		scanf("%d", &rs[i]);
		rs[i]--;
	}
	int** costs = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		costs[i] = malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			costs[i][j] = INF;
		}
		costs[i][i] = 0;
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		a--;
		b--;
		costs[a][b] = c;
		costs[b][a] = c;
	}
	int** dist = floyd_warshall(costs, n);
	int** perms = permutations(rs, R);
	ans = INF;
	for (i = 0; i < R; i++) {
		tmp = 0;
		for (j = 1; j < R; j++) {
			a = perms[i][j-1];
			b = perms[i][j];
			tmp += dist[a][b];
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}

