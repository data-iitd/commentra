#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000

// Constants for buffer sizes and modulo value
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Scanner for reading input
static char buf[INITIAL_BUF_SIZE];
static int bufIndex = 0;
static int bufSize = 0;

void initScanner() {
    setvbuf(stdin, buf, _IOFBF, initialBufSize);
}

void fillBuffer() {
    bufSize = fread(buf, 1, maxBufSize, stdin);
    bufIndex = 0;
}

int getInt() {
    if (bufIndex >= bufSize) {
        fillBuffer();
    }
    int i = 0;
    while (bufIndex < bufSize && buf[bufIndex] != ' ' && buf[bufIndex] != '\n') {
        bufIndex++;
    }
    int sign = 1;
    if (bufIndex < bufSize && buf[bufIndex] == '-') {
        sign = -1;
        bufIndex++;
    }
    while (bufIndex < bufSize && buf[bufIndex] != ' ' && buf[bufIndex] != '\n') {
        i = i * 10 + (buf[bufIndex] - '0');
        bufIndex++;
    }
    return i * sign;
}

// Graph structure to represent edges
typedef struct {
    int n;
    int **edges;
} Graph;

// Constructor for creating a new graph
Graph* newGraph(int n) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->edges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            g->edges[i][j] = 0;
        }
    }
    return g;
}

// Method to add an edge between two nodes in the graph
void addEdge(Graph *g, int u, int v) {
    g->edges[u][v] = 1;
    g->edges[v][u] = 1;
}

// Depth-first search (DFS) algorithm implementation
void dfs(int c, int **edges, int n, int *visited) {
    visited[c] = 1;

    // Visit all adjacent nodes recursively
    for (int v = 0; v < n; v++) {
        if (edges[c][v] == 1 && visited[v] == 0) {
            dfs(v, edges, n, visited);
        }
    }
}

// Breadth-first search (BFS) algorithm implementation
void bfs(int c, Graph *g) {
    int *next = (int*)malloc(g->n * sizeof(int));
    int nextIndex = 0;
    int visited[g->n];
    memset(visited, 0, sizeof(visited));

    next[nextIndex++] = c;

    // Continue until there are no more nodes to visit
    while (nextIndex > 0) {
        int u = next[0];
        nextIndex--;
        visited[u] = 1;

        // Process each adjacent node
        for (int v = 0; v < g->n; v++) {
            if (g->edges[u][v] == 1 && visited[v] == 0) {
                next[nextIndex++] = v;
            }
        }
    }
    free(next);
}

// Function to read an integer from input
int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read an array of integers from input
int* getIntArray(int n) {
    int *array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

// Function to read a string from input
char* getString() {
    char *str = (char*)malloc(maxBufSize * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read an array of strings from input
char** getStringArray(int n) {
    char **array = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        array[i] = getString();
    }
    return array;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    return (a < 0) ? -a : a;
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
    int result = 1;
    for (int i = 0; i < q; i++) {
        result *= p;
    }
    return result;
}

// Function to calculate n raised to the power of p modulo mod
int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % mod;
    } else {
        return (n * powMod(n, p - 1)) % mod;
    }
}

// Function to find the minimum value among a list of integers
int min(int nums[], int size) {
    int min = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

// Function to find the maximum value among a list of integers
int max(int nums[], int size) {
    int max = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

// Function to check if a string exists in an array of strings
int strSearch(char **a, int size, char *b) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to print an array of integers
void printIntArray(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to calculate x modulo mod
int calcMod(int x) {
    return x % mod;
}

// Function to reverse a string
char* reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    return s;
}

// Function to check if a number is prime
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

// Function to check if an integer exists in a slice
int contains(int s[], int size, int e) {
    for (int i = 0; i < size; i++) {
        if (s[i] == e) {
            return 1;
        }
    }
    return 0;
}

// Function to create a range of integers from min to max
int* makeRange(int min, int max) {
    int *a = (int*)malloc((max - min + 1) * sizeof(int));
    for (int i = 0; i <= max - min; i++) {
        a[i] = min + i;
    }
    return a;
}

// Function to generate the powerset of a given slice of integers
int** powerset(int nums[], int size) {
    int length = pow(2, size);
    int** result = (int**)malloc(length * sizeof(int*));
    int index = 0;
    result[index] = (int*)malloc(0 * sizeof(int));
    index++;

    // Generate all subsets
    for (int i = 0; i < size; i++) {
        int max = index;
        for (int j = 0; j < max; j++) {
            int* subset = (int*)malloc((j + 1) * sizeof(int));
            memcpy(subset, result[j], j * sizeof(int));
            subset[j] = nums[i];
            result[index] = subset;
            index++;
        }
    }

    return result;
}

// Function to calculate the greatest common divisor (GCD) of two integers
int calcGcd(int x, int y) {
    if (y == 0) {
        return x;
    } else if (x >= y) {
        return calcGcd(y, x % y);
    } else {
        return calcGcd(x, y % x);
    }
}

// Function to get all divisors of a number
int* getDivisor(int n) {
    int *divisor = (int*)malloc(0);
    int divisorSize = 0;
    int sqrtN = (int)sqrt(n);

    for (int i = 1; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisor = (int*)realloc(divisor, (divisorSize + 1) * sizeof(int));
            divisor[divisorSize++] = i;
            if (i != n / i) {
                divisor = (int*)realloc(divisor, (divisorSize + 1) * sizeof(int));
                divisor[divisorSize++] = n / i;
            }
        }
    }

    return divisor;
}

// Custom heap type for integers
typedef struct {
    int *data;
    int size;
} IntHeap;

// Implementing heap operations for IntHeap
void heapPush(IntHeap *h, int value) {
    h->data = (int*)realloc(h->data, (h->size + 1) * sizeof(int));
    h->data[h->size] = value;
    int i = h->size;
    while (i > 0 && h->data[i] < h->data[(i - 1) / 2]) {
        int temp = h->data[i];
        h->data[i] = h->data[(i - 1) / 2];
        h->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    h->size++;
}

int heapPop(IntHeap *h) {
    int result = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    int i = 0;
    while (2 * i + 1 < h->size) {
        int child = 2 * i + 1;
        if (child + 1 < h->size && h->data[child + 1] < h->data[child]) {
            child++;
        }
        if (h->data[i] <= h->data[child]) {
            break;
        }
        int temp = h->data[i];
        h->data[i] = h->data[child];
        h->data[child] = temp;
        i = child;
    }
    h->data = (int*)realloc(h->data, h->size * sizeof(int));
    return result;
}

// Function to calculate factorial modulo mod
int factMod(int n) {
    int value = 1;
    for (int i = 2; i <= n; i++) {
        value = (value * i) % mod;
    }
    return value;
}

// Function to calculate combinations modulo mod
int combinationMod(int n, int k) {
    int factN = factMod(n);
    int factK = factMod(k);
    int factNK = factMod(n - k);
    int factKR = powMod(factK, mod - 2);
    int factNKR = powMod(factNK, mod - 2);
    return (factN * factKR % mod * factNKR % mod) % mod;
}

// Function to find prime factors of a number
int* primeFactors(int n) {
    int *factors = (int*)malloc(0);
    int factorsSize = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors = (int*)realloc(factors, (factorsSize + 1) * sizeof(int));
            factors[factorsSize++] = i;
            n /= i;
        }
    }
    if (n > 1) {
        factors = (int*)realloc(factors, (factorsSize + 1) * sizeof(int));
        factors[factorsSize++] = n;
    }
    return factors;
}

