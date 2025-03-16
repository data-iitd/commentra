#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 1LL << 60
#define INF_BIT60 1LL << 60
#define INF_INT32 1 << 30
#define INF_BIT30 1 << 30
#define NIL -1

typedef long long ll;

char* readString() {
    // Implement readString function
}

int readInt() {
    // Implement readInt function
}

int* readIntSlice(int n) {
    // Implement readIntSlice function
}

char* readRuneSlice() {
    // Implement readRuneSlice function
}

double readFloat64() {
    // Implement readFloat64 function
}

double* readFloat64Slice(int n) {
    // Implement readFloat64Slice function
}

char* zeroPaddingRuneSlice(int num, int length) {
    // Implement zeroPaddingRuneSlice function
}

void printIntsLine(int* X, int n) {
    // Implement printIntsLine function
}

typedef struct {
    int NodeCount;
    int** Adjacents;
    int** IndexForAdjacents;
    ll* Res;
    ll** DP;
    ll Identity;
    ll (*Operate)(ll, ll);
    ll (*OperateNode)(ll, int);
} ReRootingSolver;

ReRootingSolver* newReRootingSolver(
    int nodeCount, int** edges, int edgeCount, ll identity, ll (*operate)(ll, ll), ll (*operateNode)(ll, int)
) {
    // Implement newReRootingSolver function
}

ll query(ReRootingSolver* s, int node) {
    // Implement query function
}

void initialize(ReRootingSolver* s) {
    // Implement initialize function
}

ll operate(ll l, ll r) {
    // Implement operate function
}

ll operateNode(ll v, int p) {
    // Implement operateNode function
}

int main() {
    // Implement main function
}

