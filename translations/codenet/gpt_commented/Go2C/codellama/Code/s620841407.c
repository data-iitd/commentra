
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants for general purpose usage
const int MOD = 1000000007; // Modulus for calculations
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 9223372036854775807; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // Large value for bit manipulation
const int INF_INT32 = 2147483647; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // Large value for bit manipulation
const int NIL = -1; // Nil value indicator
// Constants for graph algorithms
const int WHITE = 0; // Unvisited node
const int GRAY = 1; // Visited node
const int BLACK = 2; // Fully processed node

// Type definition for generic operations
typedef int T;

// Structure for the re-rooting solver
typedef struct {
    int NodeCount; // Number of nodes
    int **Adjacents; // Adjacency list
    int **IndexForAdjacents; // Index mapping for adjacency
    T *Res; // Result array
    T **DP; // Dynamic programming table

    T Identity; // Identity element for operations
    T (*Operate)(T, T); // Operation function
    T (*OperateNode)(T, int); // Node operation function
} ReRootingSolver;

// Constructor for ReRootingSolver
ReRootingSolver *NewReRootingSolver(int nodeCount, int **edges, T identity, T (*operate)(T, T), T (*operateNode)(T, int)) {
    ReRootingSolver *s = (ReRootingSolver *)malloc(sizeof(ReRootingSolver));

    // Initialize the solver with parameters
    s->NodeCount = nodeCount;
    s->Identity = identity;
    s->Operate = operate;
    s->OperateNode = operateNode;

    // Initialize adjacency lists
    s->Adjacents = (int **)malloc(sizeof(int *) * nodeCount);
    s->IndexForAdjacents = (int **)malloc(sizeof(int *) * nodeCount);
    for (int i = 0; i < nodeCount; i++) {
        s->Adjacents[i] = (int *)malloc(sizeof(int) * 100000);
        s->IndexForAdjacents[i] = (int *)malloc(sizeof(int) * 100000);
    }
    for (int i = 0; i < nodeCount - 1; i++) {
        // Build adjacency list and index mapping
        int x = edges[i][0] - 1;
        int y = edges[i][1] - 1;
        s->IndexForAdjacents[x][(int)s->Adjacents[y][0]] = (int)s->Adjacents[x][(int)s->Adjacents[y][0]];
        s->IndexForAdjacents[y][(int)s->Adjacents[x][0]] = (int)s->Adjacents[y][(int)s->Adjacents[x][0]];
        s->Adjacents[x][(int)s->Adjacents[y][0]] = y;
        s->Adjacents[y][(int)s->Adjacents[x][0]] = x;
    }

    // Initialize DP and result arrays
    s->DP = (T **)malloc(sizeof(T *) * nodeCount);
    s->Res = (T *)malloc(sizeof(T) * nodeCount);

    for (int i = 0; i < nodeCount; i++) {
        s->DP[i] = (T *)malloc(sizeof(T) * 100000); // Allocate DP table
    }

    // Initialize the solver if there are more than one node
    if (s->NodeCount > 1) {
        s->Initialize();
    } else {
        // Base case for a single node
        s->Res[0] = s->OperateNode(s->Identity, 0);
    }

    return s;
}

// Query function to get the result for a specific node
T Query(ReRootingSolver *s, int node) {
    return s->Res[node]; // Return the result for the queried node
}

// Initialize the re-rooting solver
void Initialize(ReRootingSolver *s) {
    int *parents = (int *)malloc(sizeof(int) * s->NodeCount);
    int *order = (int *)malloc(sizeof(int) * s->NodeCount);

    // Depth-first search to establish parent-child relationships and order of nodes
    int index = 0;
    int *stack = (int *)malloc(sizeof(int) * s->NodeCount);
    stack[0] = 0; // Start from the root node
    parents[0] = -1; // Root has no parent
    while (index < s->NodeCount) {
        int node = stack[index];
        index++;
        order[index - 1] = node; // Record the order of nodes
        for (int i = 0; i < s->Adjacents[node][0]; i++) {
            int adjacent = s->Adjacents[node][i + 1];
            if (adjacent == parents[node]) {
                continue; // Skip the parent node
            }
            stack[index] = adjacent; // Add child to the stack
            parents[adjacent] = node; // Set parent
        }
    }

    // Process nodes from leaves to root
    for (int i = s->NodeCount - 1; i >= 1; i--) {
        int node = order[i];
        int parent = parents[node];

        T accum = s->Identity; // Initialize accumulator
        int parentIndex = -1;
        for (int j = 0; j < s->Adjacents[node][0]; j++) {
            if (s->Adjacents[node][j + 1] == parent) {
                parentIndex = j; // Find index of parent
                continue;
            }
            accum = s->Operate(accum, s->DP[node][j + 1]); // Accumulate results from children
        }
        s->DP[parent][s->IndexForAdjacents[node][parentIndex]] = s->OperateNode(accum, node); // Update DP for parent
    }

    // Process nodes from root to leaves
    for (int i = 0; i < s->NodeCount; i++) {
        int node = order[i];
        T accum = s->Identity; // Initialize accumulator
        T *accumsFromTail = (T *)malloc(sizeof(T) * s->Adjacents[node][0]);
        accumsFromTail[s->Adjacents[node][0] - 1] = s->Identity; // Initialize tail accumulator
        for (int j = s->Adjacents[node][0] - 1; j >= 1; j--) {
            accumsFromTail[j - 1] = s->Operate(s->DP[node][j], accumsFromTail[j]); // Accumulate results from tail
        }
        for (int j = 0; j < s->Adjacents[node][0]; j++) {
            // Update DP for adjacent nodes
            s->DP[s->Adjacents[node][j + 1]][s->IndexForAdjacents[node][j]] = s->OperateNode(s->Operate(accum, accumsFromTail[j]), node);
            accum = s->Operate(accum, s->DP[node][j + 1]); // Update accumulator
        }
        s->Res[node] = s->OperateNode(accum, node); // Store result for the node
    }
}

// 