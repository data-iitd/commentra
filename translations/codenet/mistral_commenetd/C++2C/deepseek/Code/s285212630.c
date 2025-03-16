#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#define int long long
#define P pair_int_int
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define MAX_L 22

typedef struct {
    int _1;
    int _2;
} P;

// N: number of nodes, G: adjacency list, U: ancestor, R: depth, L: path length
int N;
P G[100000][2];
int U[MAX_L][100000], R[100000];
long long L[100000];

