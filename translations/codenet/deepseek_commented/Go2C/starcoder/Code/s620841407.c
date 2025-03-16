#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

// Constants

// Global variables

// Function prototypes

// Input

// Main
int main() {
	// Read the number of nodes and edges
	int n, m;
	scanf("%d %d", &n, &m);

	// Construct the graph from the edges
	int x, y;
	int edges[m][2];
	REP(i, m) {
		scanf("%d %d", &x, &y);
		x--;
		y--;
		edges[i][0] = x;
		edges[i][1] = y;
	}

	// Define the operations for the ReRootingSolver
	int (*f)(int, int) = [](int x, int y) { return (x * y) % m; };
	int (*g)(int, int) = [](int v, int p) { return v + 1; };

	// Initialize and use the ReRootingSolver to compute the results
	ReRootingSolver s = new_ReRootingSolver(n, edges, 1, f, g);
	for (int i = 0; i < n; i++) {
		printf("%d\n", s.Query(i) - 1);
	}

	return 0;
}

// ReRootingSolver struct for solving the re-rooting problem
typedef struct {
	int node_count;

	int **adjacents;
	int **index_for_adjacents;

	int *res;
	int **dp;

	int identity;
	int (*operate)(int, int);
	int (*operate_node)(int, int);
} ReRootingSolver;

// NewReRootingSolver initializes a new ReRootingSolver
ReRootingSolver new_ReRootingSolver(
	int node_count, int **edges, int identity,
	int (*operate)(int, int), int (*operate_node)(int, int),
) {
	ReRootingSolver s;

	s.node_count = node_count;
	s.identity = identity;
	s.operate = operate;
	s.operate_node = operate_node;

	s.adjacents = (int **)malloc(sizeof(int *) * node_count);
	s.index_for_adjacents = (int **)malloc(sizeof(int *) * node_count);
	REP(i, node_count) {
		s.index_for_adjacents[i] = (int *)malloc(sizeof(int) * (node_count - 1));
		s.adjacents[i] = (int *)malloc(sizeof(int) * (node_count - 1));
	}
	REP(i, m) {
		int x = edges[i][0];
		int y = edges[i][1];
		s.index_for_adjacents[x][s.index_for_adjacents[x][y]] = i;
		s.index_for_adjacents[y][s.index_for_adjacents[y][x]] = i;
		s.adjacents[x][s.index_for_adjacents[x][y]] = y;
		s.adjacents[y][s.index_for_adjacents[y][x]] = x;
	}

	s.dp = (int **)malloc(sizeof(int *) * node_count);
	REP(i, node_count) {
		s.dp[i] = (int *)malloc(sizeof(int) * (node_count - 1));
	}

	if (s.node_count > 1) {
		s.Initialize();
	} else {
		s.res[0] = s.operate_node(s.identity, 0);
	}

	return s;
}

// Query returns the result for a given node
int ReRootingSolver_Query(ReRootingSolver *s, int node) {
	return s->res[node];
}

// Initialize computes the dynamic programming values
void ReRootingSolver_Initialize(ReRootingSolver *s) {
	int *parents, *order;
	parents = (int *)malloc(sizeof(int) * s->node_count);
	order = (int *)malloc(sizeof(int) * s->node_count);

	// InitOrderedTree initializes the tree in a way that is useful for traversal
	int index = 0;
	int stack[s->node_count];
	stack[0] = 0;
	parents[0] = -1;
	for (int i = 0; i < s->node_count; i++) {
		int node = stack[i];
		if (node == -1) {
			continue;
		}
		order[index] = node;
		index++;
		for (int j = 0; j < s->index_for_adjacents[node][node]; j++) {
			int adjacent = s->adjacents[node][j];
			if (adjacent == parents[node]) {
				continue;
			}
			stack[i+1] = adjacent;
			parents[adjacent] = node;
		}
	}

	// fromLeaf computes values starting from the leaves
	for (int i = s->node_count - 1; i >= 1; i--) {
		int node = order[i];
		int parent = parents[node];

		int accum = s->identity;
		int parent_index = -1;
		for (int j = 0; j < s->index_for_adjacents[node][node]; j++) {
			if (s->adjacents[node][j] == parent) {
				parent_index = j;
				continue;
			}
			accum = s->operate(accum, s->dp[node][j]);
		}
		s->dp[parent][s->index_for_adjacents[node][parent_index]] = s->operate_node(accum, node);
	}

	// toLeaf computes values propagating from leaves to the root
	for (int i = 0; i < s->node_count; i++) {
		int node = order[i];
		int accum = s->identity;
		int accums_from_tail[s->index_for_adjacents[node][node]];
		accums_from_tail[s->index_for_adjacents[node][node] - 1] = s->identity;
		for (int j = s->index_for_adjacents[node][node] - 1; j >= 1; j--) {
			accums_from_tail[j - 1] = s->operate(s->dp[node][j], accums_from_tail[j]);
		}
		for (int j = 0; j < s->index_for_adjacents[node][node]; j++) {
			s->dp[s->adjacents[node][j]][s->index_for_adjacents[node][j]] = s->operate_node(s->operate(accum, accums_from_tail[j]), node);
			accum = s->operate(accum, s->dp[node][j]);
		}
		s->res[node] = s->operate_node(accum, node);
	}
}

// END-OF-CODE

