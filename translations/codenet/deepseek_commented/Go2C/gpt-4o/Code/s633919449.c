#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

<<<<<<< HEAD
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

// Function prototypes
int getInt();
void dfs(int c, int **edges, bool *visited, int n);
void bfs(int c, int **edges, int n);
int *getIntArray(int n);
void printIntArray(int *array, int n);
int calcMod(int x);
int abs(int a);
int powMod(int n, int p);
int min(int a, int b);
int max(int a, int b);
bool isPrime(int n);
int *getDivisor(int n, int *size);
int *makeRange(int min, int max, int *size);
int *powerset2(int *nums, int n, int *size);
int calcGcd(int x, int y);
int *primeFactors(int n, int *size);
int factMod(int n);
int combinationMod(int n, int k);
void reverse(char *s);

int main() {
    int N = getInt();

=======
#define MOD 1000000007

// Function to read an integer from standard input
int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to print the result based on the last digit of N
void printResult(int N) {
>>>>>>> 98c87cb78a (data updated)
    switch (N % 10) {
        case 2: case 4: case 5: case 7: case 9:
            printf("hon\n");
            break;
        case 0: case 1: case 6: case 8:
            printf("pon\n");
            break;
        case 3:
            printf("bon\n");
            break;
    }
<<<<<<< HEAD

    return 0;
}

int getInt() {
    int value;
    scanf("%d", &value);
    return value;
}

void dfs(int c, int **edges, bool *visited, int n) {
    visited[c] = true;

    for (int i = 0; i < n; i++) {
        if (edges[c][i] && !visited[i]) {
            dfs(i, edges, visited, n);
        }
    }
}

void bfs(int c, int **edges, int n) {
    int *next = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    bool *visited = (bool *)calloc(n, sizeof(bool));

    next[rear++] = c;

    while (front < rear) {
        int u = next[front++];
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (edges[u][v] && !visited[v]) {
                // Do something with v
                next[rear++] = v;
            }
        }
    }

    free(next);
    free(visited);
}

int *getIntArray(int n) {
    int *array = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = getInt();
    }
    return array;
}

void printIntArray(int *array, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int calcMod(int x) {
    return x % MOD;
}

=======
}

// Function to calculate the absolute value
>>>>>>> 98c87cb78a (data updated)
int abs(int a) {
    return a < 0 ? -a : a;
}

<<<<<<< HEAD
=======
// Function to calculate power with modulo
>>>>>>> 98c87cb78a (data updated)
int powMod(int n, int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int t = powMod(n, p / 2);
<<<<<<< HEAD
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p - 1));
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

=======
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

// Function to calculate factorial modulo
int factMod(int n) {
    int value = 1;
    for (; n > 1; n--) {
        value = (value * n) % MOD;
    }
    return value;
}

// Function to calculate combination modulo
int combinationMod(int n, int k) {
    int factN = factMod(n);
    int factK = factMod(k);
    int factNK = factMod(n - k);
    int factKR = powMod(factK, MOD - 2);
    int factNKR = powMod(factNK, MOD - 2);
    return (factN * ((factKR * factNKR) % MOD)) % MOD;
}

// Function to check if a number is prime
>>>>>>> 98c87cb78a (data updated)
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }
<<<<<<< HEAD

    return true;
}

int *getDivisor(int n, int *size) {
    int *divisor = (int *)malloc(n * sizeof(int));
    *size = 0;

    divisor[(*size)++] = 1;
    if (n != 1) {
        divisor[(*size)++] = n;
    }

    int sqrtN = (int)sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisor[(*size)++] = i;
            if (i != n / i) {
                divisor[(*size)++] = n / i;
            }
        }
    }

    return divisor;
}

int *makeRange(int min, int max, int *size) {
    *size = max - min + 1;
    int *a = (int *)malloc((*size) * sizeof(int));
    for (int i = 0; i < *size; i++) {
        a[i] = min + i;
    }
    return a;
}

int *powerset2(int *nums, int n, int *size) {
    int length = (int)pow(2, n);
    int *result = (int *)malloc(length * sizeof(int));
    *size = 0;

    result[(*size)++] = 0; // empty set

    for (int i = 0; i < n; i++) {
        int max = *size;
        for (int j = 0; j < max; j++) {
            result[(*size)++] = result[j] + nums[i];
        }
    }

    return result;
}

int calcGcd(int x, int y) {
    if (y == 0) return x;
    return calcGcd(y, x % y);
}

int *primeFactors(int n, int *size) {
    int *factors = (int *)malloc(n * sizeof(int));
    *size = 0;
    int i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            factors[(*size)++] = i;
            n /= i;
        } else {
            i++;
        }
    }
    if (n > 1) {
        factors[(*size)++] = n;
    }

    return factors;
}

int factMod(int n) {
    int value = 1;
    for (; n > 1; n--) {
        value = calcMod(value * n);
    }
    return value;
}

int combinationMod(int n, int k) {
    int factN = factMod(n);
    int factK = factMod(k);
    int factNK = factMod(n - k);
    int factKR = powMod(factK, MOD - 2);
    int factNKR = powMod(factNK, MOD - 2);
    return calcMod(factN * calcMod(factKR * factNKR));
}

=======
    return true;
}

// Main function
int main() {
    int N = getInt();
    printResult(N);
    return 0;
}

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
