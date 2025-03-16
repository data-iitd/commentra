#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define magic 1000000007

int N;
int p[200000];

// Function to check if a number exists in the array p
int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0; // Number found
        }
    }
    return 1; // Number not found
}

// Main solving function
void solve() {
    Io io = NewIo(); // Create a new IO instance for input/output
    defer io.Flush(); // Ensure the output buffer is flushed at the end

    // PARSE HELPER SESSION
    // Read and log the input values
    int X = io.NextInt(); // Read an integer
    printf("%d\n", X); // Log the integer
    N = io.NextInt(); // Read the size of the array
    printf("%d\n", N); // Log the size
    for (int i = 0; i < N; i++) {
        p[i] = io.NextInt(); // Read integers into the array p
    }
    printf("p ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", p[i]); // Log the first 10 elements of p
    }
    printf("\n");

    // Check for numbers around X that are not in the array p
    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) { // Check X - i
            printf("%d\n", X - i); // Print the result
            exit(0); // Exit the program
        }
        if (find(X + i) == 1) { // Check X + i
            printf("%d\n", X + i); // Print the result
            exit(0); // Exit the program
        }
    }

    // OUTPUT GENERATION PART
    // ans := 0
    // printf("%d\n", ans);

    // if (ans > 0) {
    //   printf("Yes\n");
    // } else {
    //   printf("No\n");
    // }

    // BFS/DFS PART
    // visited := []int{}
    // bfs/dfs(1, neighbor, func(node int) {
    // 	visited = append(visited, node);
    // });
    // printf("%d\n", visited);

    // DFS 2
    // var dp [2000000]int
    // nei := make(map[int][]int)
    // nei[0] = []int{1, 2}
    // nei[1] = []int{0}
    // nei[2] = []int{0, 3}
    // nei[3] = []int{2}
    // dfs2(0, nei, func(n, p int) {
    // 	Logf("%d -> %d\n", p, n);
    // 	dp[n] = p;
    // }, func(n, p int) {
    // 	Logf("%d -> %d\n", n, p);
    // });
    // for (int i = 0; i < 5; i++) {
    // 	printf("%d ", dp[i]);
    // }
    // printf("\n");

    // COMBINATION
    // printf("%d %d %d\n", N, M, intMax(N, M));
    // printf("Lucas %d %d\n", combMod(N, M, 13), combination(N, M));
}

// Main function to execute the program
int main() {
    solve(); // Call the solve function
    return 0;
}

// Libraries

// Io helps parsing inputs from standard input for programming contests.
typedef struct {
    FILE *file;
    char *buffer;
    size_t bufferSize;
    size_t bufferPos;
    char *tokens;
    size_t tokensSize;
    size_t tokensPos;
} Io;

// NewIo generates Io instance.
Io NewIo() {
    Io io;
    io.file = stdin;
    io.buffer = NULL;
    io.bufferSize = 0;
    io.bufferPos = 0;
    io.tokens = NULL;
    io.tokensSize = 0;
    io.tokensPos = 0;
    return io;
}

// Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
void IoFlush(Io *io) {
    fflush(io->file); // Flush the file buffer
}

// NextLine parses line as string.
char* IoNextLine(Io *io) {
    size_t newBufferSize = 128;
    if (io->buffer) {
        free(io->buffer);
    }
    io->buffer = (char*)malloc(newBufferSize);
    io->bufferSize = newBufferSize;
    io->bufferPos = 0;
    if (!fgets(io->buffer, (int)newBufferSize, io->file)) {
        return NULL;
    }
    return io->buffer;
}

// Next parse next word as string.
char* IoNext(Io *io) {
    if (io->tokensPos >= io->tokensSize) {
        char *line = IoNextLine(io);
        if (!line) {
            return NULL;
        }
        io->tokens = strtok(line, " \t\n");
        io->tokensSize = 1;
        io->tokensPos = 0;
    }
    char *token = io->tokens + io->tokensPos;
    io->tokensPos += strlen(token) + 1;
    return token;
}

// NextInt parse next word as Int.
int IoNextInt(Io *io) {
    char *token = IoNext(io);
    if (!token) {
        return INT_MIN;
    }
    return atoi(token);
}

// NextFloat parses next word as float64.
double IoNextFloat(Io *io) {
    char *token = IoNext(io);
    if (!token) {
        return HUGE_VAL;
    }
    return atof(token);
}

// PrintLn does buffer write with linefeed.
void IoPrintLn(Io *io, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(io->file, format, args);
    va_end(args);
    fprintf(io->file, "\n");
}

// Printf does formatted buffer write.
void IoPrintf(Io *io, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(io->file, format, args);
    va_end(args);
}

// PrintIntLn prints Int array in a single line.
void IoPrintIntLn(Io *io, int *a, int size) {
    for (int i = 0; i < size; i++) {
        fprintf(io->file, "%d ", a[i]);
    }
    fprintf(io->file, "\n");
}

// PrintStringLn prints string array in a single line.
void IoPrintStringLn(Io *io, char **a, int size) {
    for (int i = 0; i < size; i++) {
        fprintf(io->file, "%s ", a[i]);
    }
    fprintf(io->file, "\n");
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

// Helper functions for mathematical operations

// Returns the minimum of two integers
int intMin(int a, int b) {
    return a < b ? a : b;
}

// Returns the maximum of two integers
int intMax(int a, int b) {
    return a > b ? a : b;
}

// Direct calculation of combination
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

// Calculate combination modulo based on Lucas theorem
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

// Wrapper function for combination modulo
int combMod(int n, int m, int p) {
    return lucas(n, m, p);
}

// Breadth-First Search (BFS) implementation
void bfs(int start, int **nodes, int nodesSize, void (*fn)(int)) {
    int *frontier = (int*)malloc(nodesSize * sizeof(int));
    int frontierSize = 0;
    int *visited = (int*)calloc(nodesSize, sizeof(int));
    int visitedSize = nodesSize;

    frontier[frontierSize++] = start;

    while (frontierSize > 0) {
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
        frontierSize = nextSize;
        free(frontier);
        frontier = next;
    }

    free(visited);
}

// Depth-First Search (DFS) implementation
void dfs(int node, int **nodes, int nodesSize, void (*fn)(int)) {
    int *visited = (int*)calloc(nodesSize, sizeof(int));
    dfsRecur(node, nodes, visited, fn);
    free(visited);
}

// Recursive DFS helper function
void dfsRecur(int node, int **nodes, int *visited, void (*fn)(int)) {
    visited[node] = 1;
    fn(node);
    for (int i = 0; i < nodesSize; i++) {
        if (nodes[node][i] == 1 && visited[i] == 0) {
            dfsRecur(i, nodes, visited, fn);
        }
    }
}

// DFS with two functions: one before entering child tree, and another after
void dfs2(int node, int **nodes, int nodesSize, void (*fn1)(int, int), void (*fn2)(int, int)) {
    int *visited = (int*)calloc(nodesSize, sizeof(int));
    dfs2Recur(node, -1, nodes, visited, fn1, fn2);
    free(visited);
}

// Recursive DFS helper function with parent tracking
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

// Stack data structure implementation
typedef struct Element {
    int value;
    struct Element *next;
} Element;

typedef struct {
    Element *top;
    int size;
} Stack;

// Len returns stack height
int StackLen(Stack *s) {
    return s->size;
}

// Push puts an element on the stack.
void StackPush(Stack *s, int value) {
    Element *e = (Element*)malloc(sizeof(Element));
    e->value = value;
    e->next = s->top;
    s->top = e;
    s->size++;
}

// Pop picks out the last element from the stack.
int StackPop(Stack *s) {
    if (s->size > 0) {
        Element *e = s->top;
        int value = e->value;
        s->top = e->next;
        free(e);
        s->size--;
        return value;
    }
    return INT_MIN;
}

// Power function for integer parameters
int powerInt(int n, int p) {
    int tmp = 1;
    for (int i = 0; i < n; i++) {
        tmp *= p;
    }
    return tmp;
}

// Function to find divisors of a number
void findDivisors(int n, int **a) {
    if (n == 1) {
        return;
    }

    int sqrt = (int)sqrt(n);
    for (int i = 2; i <= sqrt; i++) {
        if (n % i == 0) {
            (*a)[0] = i;
            (*a)[1] = n / i;
            (*a) = (int*)realloc((*a), 2 * sizeof(int));
        }
    }
    (*a)[0] = n;
    (*a) = (int*)realloc((*a), 1 * sizeof(int));
}

// Function to remove duplicates from a slice
int* removeDuplicate(int *a, int size) {
    int *m = (int*)malloc(size * sizeof(int));
    int mSize = 0;
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < mSize; j++) {
            if (m[j] == a[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            m[mSize++] = a[i];
        }
    }
    int *res = (int*)malloc(mSize * sizeof(int));
    memcpy(res, m, mSize * sizeof(int));
    free(m);
    return res;
}

// Function to calculate the absolute value
int abs(int a) {
    return a > 0 ? a : -a;
}

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (a != 0) {
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}

// Function to calculate power of 2 modulo a given number
int power2mod(int n, int mod) {
    int res = 1, x = 2;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
    }
    return res;
}

// Function to calculate power of 2 with modulo magic
int power2(int n) {
    return power2mod(n, magic);
}

