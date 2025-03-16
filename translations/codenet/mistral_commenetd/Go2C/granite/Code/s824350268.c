
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
    // Read the first integer from the standard input
    int N = getInt();

    // Calculate the square root of N
    int sqrtN = (int)sqrt(N);

    // Initialize the minimum number with N
    int min = N;

    // Iterate through all numbers from 1 to the square root of N
    for (int i = 1; i <= sqrtN; i++) {
        // Check if N is divisible by i
        if (N % i!= 0) {
            continue;
        }

        // Calculate the number of divisors of i and N
        int num = i + (N / i) - 2;

        // Update the minimum number if the current number is smaller
        if (num < min) {
            min = num;
        }
    }

    // Print the minimum number
    printf("%d\n", min);

    return 0;
}

// Define a Graph data structure
typedef struct {
    int n;
    int** edges;
} Graph;

// Initialize a new Graph with n vertices
Graph* NewGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->edges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int*)malloc(n * sizeof(int));
    }
    return g;
}

// Add an edge between two vertices in the Graph
void AddEdge(Graph* g, int u, int v) {
    g->edges[v][u] = 1;
    g->edges[u][v] = 1;
}

// Depth First Search function
void dfs(int c, int** edges, int* visited) {
    // Mark the current vertex as visited
    visited[c] = 1;

    // Iterate through all neighbors of the current vertex
    for (int i = 0; i < g->n; i++) {
        if (g->edges[c][i] == 1 && visited[i] == 0) {
            dfs(i, edges, visited);
        }
    }
}

// Helper functions for reading integers and strings from the standard input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

char* getString() {
    char str[1000];
    fgets(str, 1000, stdin);
    char* s = (char*)malloc(strlen(str) * sizeof(char));
    strcpy(s, str);
    char* token = strtok(s, " \n");
    return token;
}

// Helper functions for basic arithmetic operations
int abs(int a) {
    return abs(a);
}

int pow(int p, int q) {
    return pow(p, q);
}

int powMod(int n, int p) {
    // Base case: if p is 0, return 1
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        // Recursive case: if p is even, square the base and recursively call powMod
        int t = powMod(n, p / 2);
        return calcMod(t * t);
    } else {
        // Recursive case: if p is odd, multiply the base with the result of recursively calling powMod with p-1
        return calcMod(n * powMod(n, p - 1));
    }
}

// Helper functions for finding the minimum and maximum values
int min(int...args) {
    // Base case: if there are no numbers, panic
    if (sizeof...(args) == 0) {
        printf("funciton min() requires at least one argument.\n");
        exit(1);
    }

    // Initialize the minimum value with the first number
    int res = args[0];

    // Iterate through all numbers and update the minimum value if necessary
    for (int i = 1; i < sizeof...(args); i++) {
        res = fmin(res, args[i]);
    }

    // Return the minimum value
    return res;
}

int max(int...args) {
    // Base case: if there are no numbers, panic
    if (sizeof...(args) == 0) {
        printf("funciton max() requires at least one argument.\n");
        exit(1);
    }

    // Initialize the maximum value with the first number
    int res = args[0];

    // Iterate through all numbers and update the maximum value if necessary
    for (int i = 1; i < sizeof...(args); i++) {
        res = fmax(res, args[i]);
    }

    // Return the maximum value
    return res;
}

// Helper function for searching a string in an array of strings
int strSearch(char* a[], char* b) {
    // Iterate through all strings in the array and return true if the target string is found
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }

    // If the target string is not found, return false
    return 0;
}

// Helper function for printing an integer array
void printIntArray(int array[]) {
    // Convert the integer array to a string and print it without the brackets and the leading and trailing spaces
    char strArray[1000];
    sprintf(strArray, "%d", array[0]);
    for (int i = 1; i < sizeof(array) / sizeof(array[0]); i++) {
        sprintf(strArray, "%s %d", strArray, array[i]);
    }
    printf("%s\n", strArray);
}

// Helper function for calculating the modulo operation
int calcMod(int x) {
    // Calculate the modulo of x with the modulus constant
    return x % mod;
}

// Helper function for reversing a string
char* reverse(char* s) {
    // Create a new string to store the reversed string
    char* reversed = (char*)malloc(strlen(s) * sizeof(char));

    // Iterate through the characters of the input string and store them in the reversed string in reverse order
    for (int i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = s[i];
    }

    return reversed;
}

// Helper function for checking if a number is prime
int isPrime(int n) {
    // Base case: if n is less than 2, it is not prime
    if (n < 2) {
        return 0;
    }

    // Base case: if n is 2, it is prime
    if (n == 2) {
        return 1;
    }

    // Base case: if n is even, it is not prime
    if (n % 2 == 0) {
        return 0;
    }

    // Calculate the square root of n and iterate through all odd numbers from 3 to the square root of n
    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        // If n is divisible by i, it is not prime
        if (n % i == 0) {
            return 0;
        }
    }

    // If we have reached here, n is prime
    return 1;
}

