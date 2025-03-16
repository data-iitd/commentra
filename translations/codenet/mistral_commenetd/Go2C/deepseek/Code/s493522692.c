#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Util functions
char* nextStr() {
    // Scans the next token, a rune, into sc.Text().
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    // Returns the text scanned into sc.Text() as a string.
    return line;
}

// With a comment explaining what the function does:
// Scans the next token, a rune, into sc.Text() and returns it as a string.
char* nextStr() {
    // Scans the next token, a rune, into sc.Text().
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    // Returns the text scanned into sc.Text() as a string.
    return line;
}

int nextInt() {
    // Scans the next token, a string, into sc.Text().
    // Converts the string to an integer using strconv.Atoi() and returns it.
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return -1;
    }
    int i = atoi(line);
    free(line);
    return i;
}

// With a comment explaining what the function does:
// Scans the next token, a string, into sc.Text() and converts it to an integer.
int nextInt() {
    // Scans the next token, a string, into sc.Text().
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return -1;
    }
    // Converts the string to an integer using strconv.Atoi().
    int i = atoi(line);
    // Frees the allocated memory for the line.
    free(line);
    // Returns the integer.
    return i;
}

// Helper functions for mathematical operations
int maxInt(int a, int b) {
    // Returns the maximum of two integers.
    return a > b ? a : b;
}

// With a comment explaining what the function does:
// Returns the maximum of two integers.
int maxInt(int a, int b) {
    // If 'a' is greater than 'b', return 'a'.
    return a > b ? a : b;
}

int minInt(int a, int b) {
    // Returns the minimum of two integers.
    return a < b ? a : b;
}

// With a comment explaining what the function does:
// Returns the minimum of two integers.
int minInt(int a, int b) {
    // If 'a' is greater than 'b', return 'b'.
    return a < b ? a : b;
}

int absInt(int a) {
    // Returns the absolute value of an integer.
    return a >= 0 ? a : -a;
}

// With a comment explaining what the function does:
// Returns the absolute value of an integer.
int absInt(int a) {
    // If the integer is non-negative, return it as is.
    return a >= 0 ? a : -a;
}

double absFloat64(double a) {
    // Returns the absolute value of a floating-point number.
    return a >= 0 ? a : -a;
}

// With a comment explaining what the function does:
// Returns the absolute value of a floating-point number.
double absFloat64(double a) {
    // If the floating-point number is non-negative, return it as is.
    return a >= 0 ? a : -a;
}

double maxFloat64(double a, double b) {
    // Returns the maximum of two floating-point numbers.
    return a > b ? a : b;
}

// With a comment explaining what the function does:
// Returns the maximum of two floating-point numbers.
double maxFloat64(double a, double b) {
    // If 'a' is greater than 'b', return 'a'.
    return a > b ? a : b;
}

double minFloat64(double a, double b) {
    // Returns the minimum of two floating-point numbers.
    return a < b ? a : b;
}

// With a comment explaining what the function does:
// Returns the minimum of two floating-point numbers.
double minFloat64(double a, double b) {
    // If 'a' is greater than 'b', return 'b'.
    return a < b ? a : b;
}

int str2Int(char* s) {
    // Converts a string to an integer.
    return atoi(s);
}

// With a comment explaining what the function does:
// Converts a string to an integer.
int str2Int(char* s) {
    // Attempts to convert the string to an integer using strconv.Atoi().
    return atoi(s);
}

char* reverse(char* s) {
    // Reverses a given string.
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    return s;
}

// With a comment explaining what the function does:
// Reverses a given string.
char* reverse(char* s) {
    // Initializes a rune slice with the given string.
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    // Returns the reversed string.
    return s;
}

int powInt(int p, int q) {
    // Calculates 'p' raised to the power of 'q'.
    return (int)pow(p, q);
}

// With a comment explaining what the function does:
// Calculates 'p' raised to the power of 'q'.
int powInt(int p, int q) {
    // Calculates 'p' raised to the power of 'q' using the pow() function.
    return (int)pow(p, q);
}

int isPrime(int x) {
    // Checks if a given number is prime.
    if (x == 1) {
        // 1 is not a prime number.
        return 0;
    }
    if (x == 2) {
        // 2 is a prime number.
        return 1;
    }
    // If the number is even, it's not a prime number.
    if (x % 2 == 0) {
        return 0;
    }

    // Iterates through the numbers from 3 to the square root of 'x'.
    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        // If 'x' is divisible by the current number, it's not a prime number.
        if (x % i == 0) {
            return 0;
        }
    }
    // Returns the result.
    return 1;
}

// With a comment explaining what the function does:
// Checks if a given number is prime.
int isPrime(int x) {
    // If the number is 1, it's not a prime number.
    if (x == 1) {
        return 0;
    }
    // If the number is 2, it's a prime number.
    if (x == 2) {
        return 1;
    }
    // If the number is even, it's not a prime number.
    if (x % 2 == 0) {
        return 0;
    }

    // Iterates through the numbers from 3 to the square root of 'x'.
    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        // If 'x' is divisible by the current number, it's not a prime number.
        if (x % i == 0) {
            return 0;
        }
    }
    // Returns the result.
    return 1;
}

int* PrimeFactors(int n, int* size) {
    // Finds the prime factors of a given number.
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        // Appends 2 to the result slice.
        pfs[(*size)++] = 2;
        // Divides n by 2.
        n = n / 2;
    }

    // n must be odd at this point. so we can skip one element
    // (note i = i + 2)
    for (int i = 3; i * i <= n; i = i + 2) {
        // While i divides n, appends i to the result slice and divides n by i.
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        // Appends n to the result slice.
        pfs[(*size)++] = n;
    }

    // Returns the result.
    return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number.
int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        // Appends 2 to the result slice.
        pfs[(*size)++] = 2;
        // Divides n by 2.
        n = n / 2;
    }

    // n must be odd at this point. so we can skip one element
    // (note i = i + 2)
    for (int i = 3; i * i <= n; i = i + 2) {
        // While i divides n, appends i to the result slice and divides n by i.
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        // Appends n to the result slice.
        pfs[(*size)++] = n;
    }

    // Returns the result.
    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int* PrimeFactors(int n, int* size) {
    int* pfs = (int*)malloc(100 * sizeof(int)); // Allocate memory for prime factors
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }

    return pfs;
}

int isPrime(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
   