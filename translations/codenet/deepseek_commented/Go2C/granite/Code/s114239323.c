
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;

// Reads the next integer from the input
int nextInt() {
    return nextInt(); // Comment: Reads the next integer from the input
}

// Reads a slice of integers of length N
int* nextInts(int N) {
    int* r = (int*)malloc(sizeof(int) * N); // Comment: Reads a slice of integers of length N
    for (int i = 0; i < N; i++) {
        r[i] = nextInt();
    }
    return r;
}

// Main function to solve the problem
int main() {
    // Reads the number of steps N
    int N = nextInt(); // Comment: Reads the number of steps N
    
    // Reads the list of heights h
    int* h = nextInts(N); // Comment: Reads the list of heights h
    
    // Initializes the DP array with zeros
    int* dp = (int*)malloc(sizeof(int) * N); // Comment: Initializes the DP array with zeros
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    
    // Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2])); // Comment: Computes the minimum cost to reach each step using dynamic programming
    }
    
    // Prints the minimum cost to reach the last step
    printf("%d\n", dp[N - 1]); // Comment: Prints the minimum cost to reach the last step
    
    // Frees the memory allocated for h and dp
    free(h);
    free(dp);
    
    return 0;
}

// Utility function to find the absolute value of an integer
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Utility function to find the maximum value in a slice of integers
int max(int* a, int N) {
    int r = a[0];
    for (int i = 0; i < N; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a slice of integers
int min(int* a, int N) {
    int r = a[0];
    for (int i = 0; i < N; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a slice of integers
int sum(int* a, int N) {
    int r = 0;
    for (int i = 0; i < N; i++) {
        r += a[i];
    }
    return r;
}

// Pair struct to represent a pair of integers
typedef struct {
    int a, b;
} Pair;

// Pairs slice to represent a slice of Pair
typedef struct {
    Pair* data;
    int size;
} Pairs;

// Len method to get the length of the Pairs slice
int Pairs_Len(Pairs* p) {
    return p->size;
}

// Swap method to swap two elements in the Pairs slice
void Pairs_Swap(Pairs* p, int i, int j) {
    Pair temp = p->data[i];
    p->data[i] = p->data[j];
    p->data[j] = temp;
}

// Less method to compare two elements in the Pairs slice
int Pairs_Less(Pairs* p, int i, int j) {
    return p->data[i].b < p->data[j].b;
}

// nextString function to read the next string
char* nextString() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextInt64 function to read the next 64-bit integer
long long nextInt64() {
    long long r = 0;
    char c = getchar();
    while (c!= '\n') {
        r = r * 10 + (c - '0');
        c = getchar();
    }
    return r;
}

// nextInt function to read the next integer
int nextInt() {
    int r = 0;
    char c = getchar();
    while (c!= '\n') {
        r = r * 10 + (c - '0');
        c = getchar();
    }
    return r;
}

// nextInts function to read a slice of integers of length N
int* nextInts(int N) {
    int* r = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        r[i] = nextInt();
    }
    return r;
}

// nextStrings function to read a slice of strings of length N
char** nextStrings(int N) {
    char** r = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; i++) {
        r[i] = nextString();
    }
    return r;
}

// nextFloat64 function to read the next float64
double nextFloat64() {
    double r = 0;
    char c = getchar();
    int dotCount = 0;
    while (c!= '\n') {
        if (c == '.') {
            dotCount++;
        } else {
            r = r * 10 + (c - '0');
        }
        c = getchar();
    }
    if (dotCount > 0) {
        double factor = 1;
        for (int i = 0; i < dotCount; i++) {
            factor /= 10;
        }
        r *= factor;
    }
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    int size = 100;
    char* r = (char*)malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    while (c!= '\n') {
        r[i] = c;
        i++;
        if (i == size) {
            size *= 2;
            r = (char*)realloc(r, sizeof(char) * size);
        }
        c = getchar();
    }
    r[i] = '\0';
    return r;
}

// nextLine function to read the next line
char* nextLine() {
    in