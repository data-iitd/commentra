
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

// N: number of nodes, G: adjacency list, U: ancestor, R: depth, L: path length
int N;
typedef struct {
  int to, cost;
} Edge;
Edge G[100000][20];
int U[20][100000], R[100000];
long long L[100000];

// 