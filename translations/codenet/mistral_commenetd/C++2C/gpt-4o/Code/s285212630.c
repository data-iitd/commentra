#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define int long long
#define INF 1145141919
#define MOD 1000000007
#define MAX_L 22
#define MAX_N 100000

typedef struct {
    int first;
    int second;
} P;

int N;
P G[MAX_N][MAX_N]; // Adjusted to a 2D array for adjacency list representation
int U[MAX_L][MAX_N];
int R[MAX_N];
long long L[MAX_N];

// Function prototypes can be added here if needed

// <END-OF-CODE>
