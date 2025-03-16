

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 100000

int main() {
    // Read the number of elements
    int N = nextInt();
    // Read the heights into a slice
    int h[MAX_N];
    for (int i = 0; i < N; i++) {
        h[i] = nextInt();
    }

    // Initialize a dynamic programming slice to store minimum costs
    int dp[MAX_N];
    for (int i = 0; i < N; i++) {
        dp[i] = 0; // Set initial values to zero
    }
    
    // Base case: cost to jump from the first to the second height
    dp[1] = abs(h[0] - h[1]);

    // Fill the dp slice with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    // Output the minimum cost to reach the last height
    printf("%d\n", dp[N-1]);
}

/* templates */

// Max function returns the maximum value from a slice of integers
int max(int a[], int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Min function returns the minimum value from a slice of integers
int min(int a[], int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Sum function calculates the sum of a slice of integers
int sum(int a[], int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    return r;
}

// Abs function returns the absolute value of an integer
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Pair struct represents a pair of integers
typedef struct {
    int a, b;
} Pair;

// Pairs is a slice of Pair
typedef struct {
    Pair p[MAX_N];
    int n;
} Pairs;

// Len returns the length of the Pairs slice
int len(Pairs p) {
    return p.n;
}

// Swap exchanges the elements at indices i and j in the Pairs slice
void swap(Pairs p, int i, int j) {
    Pair t = p.p[i];
    p.p[i] = p.p[j];
    p.p[j] = t;
}

// Less compares two pairs based on the second element of the pair
bool less(Pairs p, int i, int j) {
    return p.p[i].b < p.p[j].b;
}

// nextReader is a function that reads input from standard input
char* nextReader() {
    static char buf[1024];
    static char *p = buf;
    if (!p) {
        fgets(buf, 1024, stdin);
        p = buf;
    }
    char *r = p;
    while (*p && *p!='') {
        p++;
    }
    if (*p) {
        *p++ = 0;
    }
    return r;
}

// nextString reads the next string from input
char* nextString() {
    return nextReader();
}

// nextInt64 reads the next int64 from input
long long nextInt64() {
    long long v;
    sscanf(nextReader(), "%lld", &v);
    return v;
}

// nextInt reads the next int from input
int nextInt() {
    int v;
    sscanf(nextReader(), "%d", &v);
    return v;
}

// nextInts reads n integers from input and returns them as a slice
int* nextInts(int n) {
    int *r = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}

// nextStrings reads n strings from input and returns them as a slice
char** nextStrings(int n) {
    char **r = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        r[i] = nextString();
    }
    return r;
}

// nextFloat64 reads the next float64 from input
double nextFloat64() {
    double v;
    sscanf(nextReader(), "%lf", &v);
    return v;
}

# Python

# Read the number of elements
N = int(input())
# Read the heights into a slice
h = [int(x) for x in input().split()]

# Initialize a dynamic programming slice to store minimum costs
dp = [0] * N

# Base case: cost to jump from the first to the second height
dp[1] = abs(h[0] - h[1])

# Fill the dp slice with minimum costs for each position
for i in range(2, N):
    dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]))

# Output the minimum cost to reach the last height
print(dp[N-1])

Translate the above Python code to C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 100000

int main() {
    // Read the number of elements
    int N = nextInt();
    // Read the heights into a slice
    int h[MAX_N];
    for (int i = 0; i < N; i++) {
        h[i] = nextInt();
    }

    // Initialize a dynamic programming slice to store minimum costs
    int dp[MAX_N];
    for (int i = 0; i < N; i++) {
        dp[i] = 0; // Set initial values to zero
    }
    
    // Base case: cost to jump from the first to the second height
    dp[1] = abs(h[0] - h[1]);

    // Fill the dp slice with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    // Output the minimum cost to reach the last height
    printf("%d\n", dp[N-1]);
}

/* templates */

// Max function returns the maximum value from a slice of integers
int max(int a[], int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Min function returns the minimum value from a slice of integers
int min(int a[], int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Sum function calculates the sum of a slice of integers
int sum(int a[], int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    return r;
}

// Abs function returns the absolute value of an integer
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Pair struct represents a pair of integers
typedef struct {
    int a, b;
} Pair;

// Pairs is a slice of Pair
typedef struct {
    Pair p[MAX_N];
    int n;
} Pairs;

// Len returns the length of the Pairs slice
int len(Pairs p) {
    return p.n;
}

// Swap exchanges the elements at indices i and j in the Pairs slice
void swap(Pairs p, int i, int j) {
    Pair t = p.p[i];
    p.p[i] = p.p[j];
    p.p[j] = t;
}

// Less compares two pairs based on the second element of the pair
bool less(Pairs p, int i, int j) {
    return p.p[i].b < p.p[j].b;
}

// nextReader is a function that reads input from standard input
char* nextReader() {
    static char buf[1024];
    static char *p = buf;
    if (!p) {
        fgets(buf, 1024, stdin);
        p = buf;
    }
    char *r = p;
    while (*p && *p!='') {
        p++;
    }
    if (*p) {
        *p++ = 0;
    }
    return r;
}

// nextString reads the next string from input
char* nextString() {
    return nextReader();
}

// nextInt64 reads the next int64 from input
long long nextInt64() {
    long long v;
    sscanf(nextReader(), "%lld", &v);
    return v;
}

// nextInt reads the next int from input
int nextInt() {
    int v;
    sscanf(nextReader(), "%d", &v);
    return v;
}

// nextInts reads n integers from input and returns them as a slice
int* nextInts(int n) {
    int *r = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}

// nextStrings reads n strings from input and returns them as a slice
char** nextStrings(int n) {
    char **r = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        r[i] = nextString();
    }
    return r;
}

// nextFloat64 reads the next float64 from input
double nextFloat64() {
    double v;
    sscanf(nextReader(), "%lf", &v);
    return v;
}

# Ruby

# Read the number of elements
N = gets.to_i
# Read the heights into a slice
h = gets.split.map(&:to_i)

# Initialize a dynamic programming slice to store minimum costs
dp = [0] * N

# Base case: cost to jump from the first to the second height
dp[1] = h[0] - h[1]

# Fill the dp slice with minimum costs for each position
for i in 2..N-1
    dp[i] = [dp[i-1] + (h[i] - h[i-1]).abs, dp[i-2] + (h[i] - h[i-2]).abs].min
end

# Output the minimum cost to reach the last height
puts dp[N-1]

Translate the above Ruby code to C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 100000

int main() {
    // Read the number of elements
    int N = nextInt();
    // Read the heights into a slice
    int h[MAX_N];
    for (int i = 0; i < N; i++) {
        h[i] = nextInt();
    }

    // Initialize a dynamic programming slice to store minimum costs
    int dp[MAX_N];
    for (int i = 0; i < N; i++) {
        dp[i] = 0; // Set initial values to zero
    }
    
    // Base case: cost to jump from the first to the second height
    dp[1] = abs(h[0] - h[1]);

    // Fill the dp slice with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    // Output the minimum cost to reach the last height
    printf("%d\n", dp[N-1]);
}

/* templates */

// Max function returns the maximum value from a slice of integers
int max(int a[], int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Min function returns the minimum value from a slice of integers
int min(int a[], int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Sum function calculates the sum of a slice of integers
int sum(int a[], int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    return r;
}

// Abs function returns the absolute value of an integer
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Pair struct represents a pair of integers
typedef struct {
    int a, b;
} Pair;

// Pairs is a slice of Pair
typedef struct {
    Pair p[MAX_N];
    int n;
} Pairs;

// Len returns the length of the Pairs slice
int len(Pairs p) {
    return p.n;
}

// Swap exchanges the elements at indices i and j in the Pairs slice
void swap(Pairs p, int i, int j) {
