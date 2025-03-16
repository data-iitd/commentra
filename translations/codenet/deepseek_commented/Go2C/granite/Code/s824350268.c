
#include <stdio.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 1000000
#define mod 100000007

int getInt();
char* getString();
int abs(int a);
int pow(int p, int q);
int powMod(int n, int p);
int min(int nums[], int len);
int max(int nums[], int len);
int strSearch(char* a[], char* b, int len);
void printIntArray(int array[], int len);
int calcMod(int x);
char* reverse(char* s);
int isPrime(int n);

int main() {
    int N = getInt();
    int sqrtN = (int)sqrt(N);

    int min = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i!= 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        if (num < min) {
            min = num;
        }
    }

    printf("%d\n", min);
}

typedef struct {
    int n;
    int** edges;
} Graph;

Graph* NewGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->edges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int*)malloc(n * sizeof(int));
    }
    return g;
}

void AddEdge(Graph* g, int u, int v) {
    g->edges[v][u] = 1;
    g->edges[u][v] = 1;
}

void dfs(int c, int** edges, int* visited) {
    visited[c] = 1;

    for (int i = 0; i < g->n; i++) {
        if (g->edges[c][i] == 1 && visited[i] == 0) {
            dfs(i, edges, visited);
        }
    }
}

int getInt() {
    char buf[100];
    scanf("%s", buf);
    return atoi(buf);
}

char* getString() {
    char buf[100];
    scanf("%s", buf);
    return buf;
}

int abs(int a) {
    return (int)abs((double)a);
}

int pow(int p, int q) {
    return (int)pow((double)p, (double)q);
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p - 1));
    }
}

int min(int nums[], int len) {
    int res = nums[0];
    for (int i = 0; i < len; i++) {
        res = (int)min((double)res, (double)nums[i]);
    }
    return res;
}

int max(int nums[], int len) {
    int res = nums[0];
    for (int i = 0; i < len; i++) {
        res = (int)max((double)res, (double)nums[i]);
    }
    return res;
}

int strSearch(char* a[], char* b, int len) {
    for (int i = 0; i < len; i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }
    return 0;
}

void printIntArray(int array[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int calcMod(int x) {
    return x % mod;
}

char* reverse(char* s) {
    int len = strlen(s);
    char* reversed = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        reversed[i] = s[len - 1 - i];
    }
    return reversed;
}

int isPrime(int n) {
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }

    int sqrtN = (int)sqrt((double)n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

