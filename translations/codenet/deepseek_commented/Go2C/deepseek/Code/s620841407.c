#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 LONG_MAX
#define INF_BIT60 1LL << 60
#define INF_INT32 INT_MAX
#define INF_BIT30 1 << 30
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long int int64;

// Global variables
int n, m;
int edges[200000][2];

// ReRootingSolver struct for solving the re-rooting problem
typedef struct {
    int NodeCount;
    int Adjacents[200000][2];
    int IndexForAdjacents[200000][2];
    int Res[200000];
    int DP[200000][2];
    int Identity;
    int (*Operate)(int, int);
    int (*OperateNode)(int, int);
} ReRootingSolver;

// Function prototypes
void init();
void main_();
ReRootingSolver* NewReRootingSolver(int nodeCount, int edges[][2], int identity, int (*operate)(int, int), int (*operateNode)(int, int));
int Query(ReRootingSolver* s, int node);
void Initialize(ReRootingSolver* s);

// Main function to execute the program
int main() {
    init();
    main_();
    return 0;
}

void init() {
    // Initialize input reader and output writer
    // bufio.ScanWords <---> bufio.ScanLines
    // ReadString = newReadString(os.Stdin, bufio.ScanWords);
    // stdout = bufio.NewWriter(os.Stdout);
}

void main_() {
    // Read the number of nodes and edges
    n = ReadInt();
    m = ReadInt();

    // Construct the graph from the edges
    for (int i = 0; i < n-1; i++) {
        int x = ReadInt() - 1;
        int y = ReadInt() - 1;
        edges[i][0] = x;
        edges[i][1] = y;
    }

    // Define the operations for the ReRootingSolver
    int (*f)(int, int) = operate;
    int (*g)(int, int) = operateNode;

    // Initialize and use the ReRootingSolver to compute the results
    ReRootingSolver* s = NewReRootingSolver(n, edges, 1, f, g);
    for (int i = 0; i < n; i++) {
        printf("%d\n", Query(s, i) - 1);
    }
}

int operate(int l, int r) {
    return (l * r) % m;
}

int operateNode(int v, int p) {
    return v + 1;
}

ReRootingSolver* NewReRootingSolver(int nodeCount, int edges[][2], int identity, int (*operate)(int, int), int (*operateNode)(int, int)) {
    ReRootingSolver* s = (ReRootingSolver*)malloc(sizeof(ReRootingSolver));
    s->NodeCount = nodeCount;
    s->Identity = identity;
    s->Operate = operate;
    s->OperateNode = operateNode;

    for (int i = 0; i < nodeCount; i++) {
        s->Adjacents[i][0] = edges[i][0];
        s->Adjacents[i][1] = edges[i][1];
        s->IndexForAdjacents[i][0] = 0;
        s->IndexForAdjacents[i][1] = 0;
    }

    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            s->DP[i][j] = 0;
        }
    }

    for (int i = 0; i < nodeCount; i++) {
        s->Res[i] = 0;
    }

    if (nodeCount > 1) {
        Initialize(s);
    } else {
        s->Res[0] = s->OperateNode(s->Identity, 0);
    }

    return s;
}

int Query(ReRootingSolver* s, int node) {
    return s->Res[node];
}

void Initialize(ReRootingSolver* s) {
    int parents[s->NodeCount];
    int order[s->NodeCount];

    // InitOrderedTree initializes the tree in a way that is useful for traversal
    int index = 0;
    int stack[s->NodeCount];
    int stack_top = 0;
    stack[stack_top++] = 0;
    parents[0] = -1;
    while (stack_top > 0) {
        int node = stack[--stack_top];
        order[index++] = node;
        for (int i = 0; i < 2; i++) {
            int adjacent = s->Adjacents[node][i];
            if (adjacent == parents[node]) {
                continue;
            }
            stack[stack_top++] = adjacent;
            parents[adjacent] = node;
        }
    }

    // fromLeaf computes values starting from the leaves
    for (int i = s->NodeCount - 1; i >= 1; i--) {
        int node = order[i];
        int parent = parents[node];

        int accum = s->Identity;
        int parentIndex = -1;
        for (int j = 0; j < 2; j++) {
            if (s->Adjacents[node][j] == parent) {
                parentIndex = j;
                continue;
            }
            accum = s->Operate(accum, s->DP[node][j]);
        }
        s->DP[parent][s->IndexForAdjacents[node][parentIndex]] = s->OperateNode(accum, node);
    }

    // toLeaf computes values propagating from leaves to the root
    for (int i = 0; i < s->NodeCount; i++) {
        int accum = s->Identity;
        int accumsFromTail[2] = {s->Identity, s->Identity};
        for (int j = 1; j >= 0; j--) {
            accumsFromTail[j] = s->Operate(s->DP[order[i]][j], accumsFromTail[j+1]);
        }
        for (int j = 0; j < 2; j++) {
            s->DP[s->Adjacents[order[i]][j]][s->IndexForAdjacents[order[i]][j]] = s->OperateNode(s->Operate(accum, accumsFromTail[j]), order[i]);
            accum = s->Operate(accum, s->DP[order[i]][j]);
        }
        s->Res[order[i]] = s->OperateNode(accum, order[i]);
    }
}

int ReadInt() {
    char str[16];
    scanf("%s", str);
    return atoi(str);
}

