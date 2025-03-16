/*
 depth first search algorithm implementation in C++
 not lying in the stack
 */
#include <iostream>
using namespace std;

static const int N = 100; /* maximum number of vertices in the graph */
static const int WHITE = 0; /* unvisited vertex */
static const int GRAY = 1; /* vertex is being explored */
static const int BLACK = 2; /* vertex has been explored */

int M[N][N], n; /* adjacency matrix and number of vertices */
int color[N], d[N], f[N], tt; /* arrays for depth first search */

/*
 depth first search visit function
 sets the color, depth and finishing time of a vertex
 */
void dfs_visit(int u) {
	int v;
	color[u] = GRAY; /* mark the current vertex as being explored */
	d[u] = ++tt; /* record the discovery time */
	for (v = 0; v < n; v++) {
		if (M[u][v] == 0)
			continue; /* if there is no edge between u and v, skip */
		if (color[v] == WHITE) {
			dfs_visit(v); /* recursively call dfs_visit for the neighbor v */
		}
	}
	color[u] = BLACK; /* mark the current vertex as explored */
	f[u] = ++tt; /* record the finishing time */
}

/*
 depth first search function
 initializes the arrays and performs the DFS traversal
 */
void dfs() {
	int u;
	for (int i = 0; i < n; i++) {
		color[i] = WHITE; /* initialize all vertices as unvisited */
	}
	tt = 0;

	for (u = 0; u < n; u++) {
		if (color[u] == WHITE) {
			dfs_visit(u); /* call dfs_visit for the first unvisited vertex */
		}
	}

	/* print the results */
	for (int i = 0; i < n; i++)
		cout << i + 1 << " " << d[i] << " " << f[i] << endl;
}

int main() {
	int k, u, v;
	cin >> n; /* read the number of vertices */

	/* initialize the adjacency matrix with zeros */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			M[i][j] = 0;
	}

	/* read the edges and fill the adjacency matrix */
	for (int i = 0; i < n; i++) {
		cin >> u >> k;
		u--;
		for (int j = 0; j < k; j++) {
			cin >> v;
			v--;
			M[u][v] = 1;
		}
	}

	/* perform depth first search */
	dfs();

	return 0;
}
