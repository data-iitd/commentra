#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define magic 1000000007

int N;
int p[200000];

int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    // PARSE HELPER SESSION
    // STR := io.Next()
    // Log("string", STR)

    // F := io.NextFloat()
    // Log("float", F)

    // parsing int array
    int X;
    scanf("%d", &X);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) {
            printf("%d\n", X - i);
            exit(0);
        }
        if (find(X + i) == 1) {
            printf("%d\n", X + i);
            exit(0);
        }
    }
}

int main() {
    // solve();

    // OUTPUT GENERATION PART
    // ans := 0
    // fmt.Printf("%v\n", ans)

    // if ans > 0 {
    //   fmt.Printf("Yes\n")
    // } else {
    //   fmt.Printf("No\n")
    // }

    // BFS/DFS PART
    // visited := []int{}
    // bfs/dfs(1, neighbor, func(node int) {
    // 	visited = append(visited, node)
    // })
    // fmt.Println(visited)

    // DFS 2
    // var dp [2000000]int
    // nei := make(map[int][]int)
    // nei[0] = []int{1, 2}
    // nei[1] = []int{0}
    // nei[2] = []int{0, 3}
    // nei[3] = []int{2}
    // dfs2(0, nei, func(n, p int) {
    // 	Logf("%v -> %v\n", p, n)
    // 	dp[n] = p
    // }, func(n, p int) {
    // 	Logf("%v -> %v\n", n, p)
    // })
    // Logf("%v\n", dp[0:5])

    // COMBINATION
    // fmt.Printf("%d %d %d\n", N, M, intMax(N, M))
    // fmt.Printf("Lucas %d %d\n", combMod(N, M, 13), combination(N, M))

    solve();

    return 0;
}

// Libraries

// Io helps parsing inputs from standard input for programming contest.
typedef struct {
    FILE *input;
    FILE *output;
    char **tokens;
    int nextToken;
} Io;

// NewIo generates Io instance.
Io* NewIo() {
    Io *io = (Io*)malloc(sizeof(Io));
    io->input = stdin;
    io->output = stdout;
    io->tokens = NULL;
    io->nextToken = 0;
    return io;
}

// Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
void Flush(Io *io) {
    fflush(io->output);
}

// NextLine parses line as string.
char* NextLine(Io *io) {
    char *buffer = NULL;
    size_t size = 0;
    if (getline(&buffer, &size, io->input) == -1) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

// Next parse next word as string.
char* Next(Io *io) {
    while (io->nextToken >= (io->tokens ? strlen(io->tokens[0]) : 0)) {
        char *line = NextLine(io);
        if (line == NULL) {
            return NULL;
        }
        io->tokens = (char**)malloc(sizeof(char*));
        io->tokens[0] = line;
        io->nextToken = 0;
    }
    char *r = io->tokens[io->nextToken];
    io->nextToken++;
    return r;
}

// NextInt parse next word as Int.
int NextInt(Io *io) {
    char *token = Next(io);
    if (token == NULL) {
        return 0; // or handle error
    }
    return atoi(token);
}

// NextFloat parses next word as float64.
double NextFloat(Io *io) {
    char *token = Next(io);
    if (token == NULL) {
        return 0.0; // or handle error
    }
    return atof(token);
}

// PrintLn does buffer write with linefeed.
void PrintLn(Io *io, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(io->output, format, args);
    fprintf(io->output, "\n");
    va_end(args);
}

// Printf does formatted buffer write.
void Printf(Io *io, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(io->output, format, args);
    va_end(args);
}

// PrintIntLn prints Int array in a single line.
void PrintIntLn(Io *io, int *a, int size) {
    for (int i = 0; i < size; i++) {
        fprintf(io->output, "%d ", a[i]);
    }
    fprintf(io->output, "\n");
}

// PrintStringLn prints string array in a single line.
void PrintStringLn(Io *io, char **a, int size) {
    for (int i = 0; i < size; i++) {
        fprintf(io->output, "%s ", a[i]);
    }
    fprintf(io->output, "\n");
}

// Log print single value to standard output (contest server ignores this so you don't have to remove when finishing)
void Log(const char *name, int value) {
    fprintf(stderr, "%s=%d\n", name, value);
}

// Logf print formatted output to standard output (contest server ignores this so you don't have to remove when finishing)
void Logf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

int intMin(int a, int b) {
    return a < b ? a : b;
}

int intMax(int a, int b) {
    return a > b ? a : b;
}

// direct calculation of combination
// n, m should be "small"
int combination(int n, int m) {
    if (m > n) {
        return 0;
    } else if (m == n || m == 0) {
        return 1;
    } else {
        int res = 1;
        for (int i = 0; i < m; i++) {
            res *= (n - i);
        }
        for (int i = 1; i <= m; i++) {
            res /= i;
        }
        return res;
    }
}

// caluclate combination modulo based on Lucas theorem
int lucas(int n, int m, int p) {
    int ntemp = n;
    int mtemp = m;
    int res = 1;
    for (int i = 0; i < 100; i++) {
        int nreminder = ntemp % p;
        ntemp = ntemp / p;
        int mreminder = mtemp % p;
        mtemp = mtemp / p;
        res = res * (combination(nreminder, mreminder) % p) % p;
        if (ntemp == 0) {
            break;
        }
    }
    return res % p;
}

int combMod(int n, int m, int p) {
    return lucas(n, m, p);
}

void bfs(int start, int **nodes, int nodesSize, void (*fn)(int)) {
    int *frontier = (int*)malloc(sizeof(int) * nodesSize);
    int frontierSize = 0;
    int *visited = (int*)calloc(nodesSize, sizeof(int));

    frontier[frontierSize++] = start;

    while (frontierSize > 0) {
        int *next = (int*)malloc(sizeof(int) * nodesSize);
        int nextSize = 0;
        for (int i = 0; i < frontierSize; i++) {
            int node = frontier[i];
            visited[node] = 1;
            fn(node);
            for (int j = 0; j < nodesSize; j++) {
                if (nodes[node][j] == 1 && visited[j] == 0) {
                    next[nextSize++] = j;
                }
            }
        }
        free(frontier);
        frontier = next;
        frontierSize = nextSize;
    }
    free(visited);
}

void dfs(int node, int **nodes, int nodesSize, void (*fn)(int)) {
    int *visited = (int*)calloc(nodesSize, sizeof(int));
    dfsRecur(node, nodes, visited, fn);
    free(visited);
}

void dfsRecur(int node, int **nodes, int *visited, void (*fn)(int)) {
    visited[node] = 1;
    fn(node);
    for (int i = 0; i < nodesSize; i++) {
        if (nodes[node][i] == 1 && visited[i] == 0) {
            dfsRecur(i, nodes, visited, fn);
        }
    }
}

// handles 2 function, one is before entering child tree, and another is
// after entering child tree.
void dfs2(int node, int **nodes, int nodesSize, void (*fn1)(int, int), void (*fn2)(int, int)) {
    int *visited = (int*)calloc(nodesSize, sizeof(int));
    dfs2Recur(node, -1, nodes, visited, fn1, fn2);
    free(visited);
}

void dfs2Recur(int node, int parent, int **nodes, int *visited, void (*fn1)(int, int), void (*fn2)(int, int)) {
    visited[node] = 1;
    if (fn1 != NULL) {
        fn1(node, parent);
    }
    for (int i = 0; i < nodesSize; i++) {
        if (nodes[node][i] == 1 && visited[i] == 0) {
            dfs2Recur(i, node, nodes, visited, fn1, fn2);
        }
    }
    if (fn2 != NULL) {
        fn2(node, parent);
    }
}

// Stack data structure
typedef struct Element {
    int value;
    struct Element *next;
} Element;

typedef struct {
    Element *top;
    int size;
} Stack;

// Len returns stack height
int Len(Stack *s) {
    return s->size;
}

// Push put a element on the stack.
void Push(Stack *s, int value) {
    Element *e = (Element*)malloc(sizeof(Element));
    e->value = value;
    e->next = s->top;
    s->top = e;
    s->size++;
}

// Pop picks out the last element from the stack.
int Pop(Stack *s) {
    if (s->size > 0) {
        int value = s->top->value;
        Element *e = s->top;
        s->top = s->top->next;
        free(e);
        s->size--;
        return value;
    }
    return -1; // or handle error
}

// powerInt (use math.Pow() for float parameters)
int powerInt(int n, int p) {
    int tmp = 1;
    for (int i = 0; i < n; i++) {
        tmp *= p;
    }
    return tmp;
}

void findDivisors(int n, int **a) {
    if (n == 1) {
        return;
    }

    int sqrt = (int)sqrt(n);
    for (int i = 2; i <= sqrt; i++) {
        if (n % i == 0) {
            (*a)[0] = i;
            (*a)[1] = n / i;
            *a = (int*)realloc(*a, 2 * sizeof(int));
        }
    }
    (*a)[0] = n;
}

int* removeDuplicate(int *a, int size) {
    int *m = (int*)malloc(size * sizeof(int));
    int *res = (int*)malloc(size * sizeof(int));
    int resSize = 0;
    for (int i = 0; i < size; i++) {
        m[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (m[a[i]] == 0) {
            m[a[i]] = 1;
            res[resSize++] = a[i];
        }
    }
    res = (int*)realloc(res, resSize * sizeof(int));
    free(m);
    return res;
}

int abs(int a) {
    return a > 0 ? a : -a;
}

// var gcdmap map[int](map[int]int)
// int gcd(int a, int b) {
// 	ina := a
// 	inb := b
// 	if _, ok := gcdmap[a]; !ok {
// 		gcdmap[a] = make(map[int]int)
// 	}
// 	if _, ok := gcdmap[ina][inb]; ok {
// 		return gcdmap[ina][inb]
// 	}
// 	for b != 0 {
// 		t := b
// 		b = a % b
// 		a = t
// 	}
// 	gcdmap[ina][inb] = a
// 	return a
// }

int gcd(int a, int b) {
    while (a != 0) {
        int t = a;
        a = b % a;
        b = t;
    }
    return b;
}

int power2mod(int n, int mod) {
    int res = 1, x = 2;
    for (; n > 0; n >>= 1) {
        if (n & 1 == 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
    }
    return res;
}

int power2(int n) {
    return power2mod(n, magic);
}

