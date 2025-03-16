#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECURSION_LIMIT 10000000

// Set the maximum recursion limit to handle deep recursions
void set_recursion_limit() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    #ifdef _WIN32
        _set_recursion_limit(MAX_RECURSION_LIMIT);
    #else
        struct rlimit rlim;
        if (getrlimit(RLIMIT_STACK, &rlim) == 0) {
            rlim.rlim_cur = MAX_RECURSION_LIMIT;
            setrlimit(RLIMIT_STACK, &rlim);
        }
    #endif
}

// Function to read a single line of input
char* input() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    return line;
}

// Function to read a list of integers from a single line of input
int* get_nums_l() {
    char* line = input();
    int* nums = malloc(sizeof(int) * 100000); // Adjust size as needed
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        nums[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line);
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
    char* buffer = NULL;
    size_t size = 0;
    if (getline(&buffer, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    int* nums = malloc(sizeof(int) * 100000); // Adjust size as needed
    char* token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL) {
        nums[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(buffer);
    return nums;
}

// Generator function to yield elements from an iterable within a specified range
int* rangeI(int* it, int l, int r) {
    int* result = malloc(sizeof(int) * (r - l));
    int index = 0;
    for (int i = 0; it[i] != -1; i++) {
        if (l <= i && i < r) {
            result[index++] = it[i];
        } else if (l >= r) {
            break;
        }
    }
    result[index] = -1; // Sentinel value to indicate end of array
    return result;
}

// Debugging function to print debug messages to stderr
void log(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

// Define a large constant for infinity
const long long INF = 999999999999999999LL;

// Define a modulus constant for calculations
const int MOD = 1000000007;

// Read an integer 'n' from input
int read_int() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to perform prime factorization of a number
int* prime_factorize(int n) {
    int* a = malloc(sizeof(int) * 100000); // Adjust size as needed
    int index = 0;
    // Divide n by 2 until it is odd
    while (n % 2 == 0) {
        a[index++] = 2;
        n /= 2;
    }
    // Check for odd factors from 3 upwards
    for (int f = 3; f * f <= n; f += 2) {
        while (n % f == 0) {
            a[index++] = f;
            n /= f;
        }
    }
    // If n is still greater than 1, it is a prime factor
    if (n > 1) {
        a[index++] = n;
    }
    return a;
}

// Main function
int main() {
    set_recursion_limit();
    int n = read_int();
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int* fac_ = prime_factorize(n);
    int* fac = malloc(sizeof(int) * 100000); // Adjust size as needed
    int fac_index = 0;
    for (int i = 0; fac_[i] != -1; i++) {
        int found = 0;
        for (int j = 0; j < fac_index; j++) {
            if (fac[j] == fac_[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            fac[fac_index++] = fac_[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < fac_index; i++) {
        int x = 0;
        for (int j = 1; j <= 99999999; j++) {
            if (x + j <= fac[i]) {
                x += j;
                ans++;
            } else {
                break;
            }
        }
    }
    printf("%d\n", ans);
    free(fac_);
    free(fac);
    return 0;
}
