
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int **edges = malloc(sizeof(int*) * n);
	REP(i, n) {
		edges[i] = malloc(sizeof(int) * n);
	}

	REP(i, n-1) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;

		edges[x][y] = 1;
		edges[y][x] = 1;
	}

	int f(int x, int y) {
		return (x * y) % m;
	}

	int g(int v, int p) {
		return v + 1;
	}

	ReRootingSolver *s = NewReRootingSolver(n, edges, 1, f, g);
	for (int i = 0; i < n; i++) {
		printf("%d\n", s->Query(i) - 1);
	}

	return 0;
}

struct ReRootingSolver {
	int NodeCount;

	int **Adjacents;
	int **IndexForAdjacents;

	int *Res;
	int **DP;

	int Identity;
	int (*Operate)(int, int);
	int (*OperateNode)(int, int);
};

ReRootingSolver *NewReRootingSolver(
	int nodeCount, int **edges, int identity, int (*operate)(int, int), int (*operateNode)(int, int),
) {
	ReRootingSolver *s = malloc(sizeof(ReRootingSolver));

	s->NodeCount = nodeCount;
	s->Identity = identity;
	s->Operate = operate;
	s->OperateNode = operateNode;

	s->Adjacents = malloc(sizeof(int*) * nodeCount);
	s->IndexForAdjacents = malloc(sizeof(int*) * nodeCount);
	REP(i, nodeCount) {
		s->IndexForAdjacents[i] = malloc(sizeof(int) * nodeCount);
	}

	REP(i, nodeCount) {
		REP(j, nodeCount) {
			s->IndexForAdjacents[i][j] = 0;
		}
		s->Adjacents[i] = malloc(sizeof(int) * nodeCount);
	}

	REP(i, nodeCount) {
		REP(j, nodeCount) {
			s->Adjacents[i][j] = 0;
		}
	}

	REP(i, nodeCount) {
		s->Adjacents[i] = edges[i];
	}

	s->DP = malloc(sizeof(int*) * nodeCount);
	REP(i, nodeCount) {
		s->DP[i] = malloc(sizeof(int) * nodeCount);
	}

	s->Res = malloc(sizeof(int) * nodeCount);

	if (s->NodeCount > 1) {
		s->Initialize();
	} else {
		s->Res[0] = s->OperateNode(s->Identity, 0);
	}

	return s;
}

int Query(ReRootingSolver *s, int node) {
	return s->Res[node];
}

void Initialize(ReRootingSolver *s) {
	int *parents = malloc(sizeof(int) * s->NodeCount);
	int *order = malloc(sizeof(int) * s->NodeCount);

	// InitOrderedTree
	int index = 0;
	int *stack = malloc(sizeof(int) * s->NodeCount);
	stack[0] = 0;
	parents[0] = -1;
	for (int i = 0; i < s->NodeCount; i++) {
		int node = stack[i];
		stack[i] = 0;
		order[index] = node;
		index++;
		for (int j = 0; j < s->NodeCount; j++) {
			int adjacent = s->Adjacents[node][j];
			if (adjacent == parents[node]) {
				continue;
			}
			stack[i+1] = adjacent;
			parents[adjacent] = node;
			break;
		}
	}

	// fromLeaf
	for (int i = s->NodeCount - 1; i >= 1; i--) {
		int node = order[i];
		int parent = parents[node];

		int accum = s->Identity;
		int parentIndex = -1;
		for (int j = 0; j < s->NodeCount; j++) {
			if (s->Adjacents[node][j] == parent) {
				parentIndex = j;
				continue;
			}
			accum = s->Operate(accum, s->DP[node][j]);
		}
		s->DP[parent][s->IndexForAdjacents[node][parentIndex]] = s->OperateNode(accum, node);
	}

	// toLeaf
	for (int i = 0; i < s->NodeCount; i++) {
		int node = order[i];
		int accum = s->Identity;
		int *accumsFromTail = malloc(sizeof(int) * s->NodeCount);
		accumsFromTail[s->NodeCount - 1] = s->Identity;
		for (int j = s->NodeCount - 1; j >= 1; j--) {
			accumsFromTail[j-1] = s->Operate(s->DP[node][j], accumsFromTail[j]);
		}
		for (int j = 0; j < s->NodeCount; j++) {
			s->DP[s->Adjacents[node][j]][s->IndexForAdjacents[node][j]] = s->OperateNode(s->Operate(accum, accumsFromTail[j]), node);
			accum = s->Operate(accum, s->DP[node][j]);
		}
		s->Res[node] = s->OperateNode(accum, node);
	}
}

