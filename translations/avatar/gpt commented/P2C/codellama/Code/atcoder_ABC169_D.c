
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Set the maximum recursion limit to handle deep recursions
#define MAX_RECURSION_LIMIT 10000000

// Function to read a single line of input
char* input() {
    char* line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

// Function to read a list of integers from a single line of input
int* get_nums_l() {
    char* line = input();
    int* nums = malloc(sizeof(int) * 1000000);
    int i = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        nums[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return nums;
}

// Function to read 'n' integers from input, one per line
int* get_nums_n(int n) {
    int* nums = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        nums[i] = atoi(input());
    }
    return nums;
}

// Function to read all integers from standard input
int* get_all_int() {
    int* nums = malloc(sizeof(int) * 1000000);
    int i = 0;
    char* line = input();
    char* token = strtok(line, " ");
    while (token != NULL) {
        nums[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return nums;
}

// Generator function to yield elements from an iterable within a specified range
int* rangeI(int* it, int l, int r) {
    int i = 0;
    while (it[i] != 0) {
        if (l <= i && i < r) {
            yield it[i];
        }
        i++;
    }
    return it;
}

// Debugging function to print debug messages to stderr
void log(char* msg) {
    printf("DEBUG: %s\n", msg);
}

// Define a large constant for infinity
#define INF 999999999999999999999999

// Define a modulus constant for calculations
#define MOD 1000000007

// Read an integer 'n' from input
int n = atoi(input());

// If n is 1, print 0 and exit
if (n == 1) {
    printf("0\n");
    exit(0);
}

// Function to perform prime factorization of a number
int* prime_factorize(int n) {
    int* a = malloc(sizeof(int) * 1000000);
    int i = 0;
    // Divide n by 2 until it is odd
    while (n % 2 == 0) {
        a[i++] = 2;
        n /= 2;
    }
    
    // Check for odd factors from 3 upwards
    int f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            a[i++] = f;
            n /= f;
        } else {
            f += 2;
        }
    }
    
    // If n is still greater than 1, it is a prime factor
    if (n != 1) {
        a[i++] = n;
    }
    
    return a;
}

// Perform prime factorization on n
int* fac_ = prime_factorize(n);

// Count the occurrences of each prime factor
int* fac = malloc(sizeof(int) * 1000000);
int i = 0;
while (fac_[i] != 0) {
    fac[fac_[i]]++;
    i++;
}

// Initialize the answer variable
int ans = 0;

// Calculate the number of ways to express the prime factors
for (int p = 0; p < 1000000; p++) {
    int x = fac[p];
    // For each prime factor's exponent, calculate how many times it can be used
    for (int i = 1; i < 99999999; i++) {
        if (x >= i) {
            x -= i;
            ans++;
        } else {
            break;
        }
    }
}

// Print the final answer
printf("%d\n", ans);

