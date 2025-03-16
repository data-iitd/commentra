
#include <stdio.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 10000000
#define mod 1e9 + 7

int getInt();
char* getString();
int abs(int a);
int pow(int p, int q);
int powMod(int n, int p);
int min(int...);
int max(int...);
int strSearch(char* a[], char* b);
void printIntArray(int array[]);
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
    return 0;
}

typedef struct {
    int n;
    int edges[1000][1000];
} Graph;

Graph* NewGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    for (int i = 0; i < n; i++) {
        g->edges[i] = NULL;
    }
    return g;
}

void AddEdge(Graph* g, int u, int v) {
    g->edges[v] = (int*)malloc(sizeof(int));
    g->edges[v][0] = u;
    g->edges[v][1] = 0;
    g->edges[u] = (int*)malloc(sizeof(int));
    g->edges[u][0] = v;
    g->edges[u][1] = 0;
}

void dfs(int c, int edges[1000][1000], int visited[1000]) {
    visited[c] = 1;
    for (int i = 0; i < edges[c][1]; i++) {
        int v = edges[c][i];
        if (visited[v] == 0) {
            dfs(v, edges, visited);
        }
    }
}

int getInt() {
    int c;
    while ((c = getchar())!= EOF) {
        if (c >= '0' && c <= '9') {
            ungetchar(c);
            break;
        }
    }
    int res = 0;
    scanf("%d", &res);
    return res;
}

char* getString() {
    int c;
    while ((c = getchar())!= EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            ungetchar(c);
            break;
        }
    }
    char res[100];
    fgets(res, 100, stdin);
    char* p = malloc(strlen(res) + 1);
    strcpy(p, res);
    char* p2 = p;
    while (*p2!= '\n') {
        p2++;
    }
    *p2 = '\0';
    return p;
}

int abs(int a) {
    return (int)fabs(a);
}

int pow(int p, int q) {
    int res = 1;
    for (int i = 0; i < q; i++) {
        res *= p;
    }
    return res;
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

int min(int...nums) {
    int res = nums[0];
    for (int i = 1; i < sizeof(nums) / sizeof(int); i++) {
        res = res < nums[i]? res : nums[i];
    }
    return res;
}

int max(int...nums) {
    int res = nums[0];
    for (int i = 1; i < sizeof(nums) / sizeof(int); i++) {
        res = res > nums[i]? res : nums[i];
    }
    return res;
}

int strSearch(char* a[], char* b) {
    for (int i = 0; i < sizeof(a) / sizeof(char*); i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }
    return 0;
}

void printIntArray(int array[]) {
    printf("[");
    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        printf("%d", array[i]);
        if (i < sizeof(array) / sizeof(int) - 1) {
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
    char* res = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        res[i] = s[len - 1 - i];
    }
    res[len] = '\0';
    return res;
}

int isPrime(int n) {
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }
    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}