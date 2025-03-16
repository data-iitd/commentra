
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
char* nextStr() {
    char* str = (char*)malloc(100 * sizeof(char));
    fgets(str, 100, stdin);
    return str;
}

// nextInt reads the next integer from input
int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// maxInt returns the maximum of two integers
int maxInt(int a, int b) {
    return (a > b)? a : b;
}

// minInt returns the minimum of two integers
int minInt(int a, int b) {
    return (a < b)? a : b;
}

// absInt returns the absolute value of an integer
int absInt(int a) {
    return (a < 0)? -a : a;
}

// absFloat64 returns the absolute value of a float64
double absFloat64(double a) {
    return (a < 0)? -a : a;
}

// maxFloat64 returns the maximum of two float64 values
double maxFloat64(double a, double b) {
    return (a > b)? a : b;
}

// minFloat64 returns the minimum of two float64 values
double minFloat64(double a, double b) {
    return (a < b)? a : b;
}

// str2Int converts a string to an integer
int str2Int(char* s) {
    int n = 0;
    sscanf(s, "%d", &n);
    return n;
}

// reverse returns the reversed string
char* reverse(char* s) {
    int len = strlen(s);
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        reversed[i] = s[len - 1 - i];
    }
    reversed[len] = '\0';
    return reversed;
}

// powInt calculates p raised to the power of q
int powInt(int p, int q) {
    return (int)pow(p, q);
}

// isPrime checks if a number is prime
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

    int b = 1;
    int rootx = sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            b = 0;
            break;
        }
    }
    return b;
}

// PrimeFactors returns the prime factors of a number
int* PrimeFactors(int n) {
    int* pfs = (int*)malloc(100 * sizeof(int));
    int count = 0;

    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs[count++] = 2;
        n = n / 2;
    }

    // n must be odd at this point, so we can skip one element
    for (int i = 3; i * i <= n; i = i + 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs[count++] = i;
            n = n / i;
        }
    }

    // Handle the case when n is a prime number greater than 2
    if (n > 2) {
        pfs[count++] = n;
    }

    return pfs;
}

// PrimeFactorsMap returns a map of prime factors and their counts
int* PrimeFactorsMap(int n) {
    int* pfs = (int*)malloc(100 * sizeof(int));
    int count = 0;

    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs[count++] = 2;
        n = n / 2;
    }

    // n must be odd at this point, so we can skip one element
    for (int i = 3; i * i <= n; i = i + 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs[count++] = i;
            n = n / i;
        }
    }

    // Handle the case when n is a prime number greater than 2
    if (n > 2) {
        pfs[count++] = n;
    }

    return pfs;
}

// sumInts returns the sum of a slice of integers
int sumInts(int* x, int len) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += x[i];
    }
    return total;
}

// gcd calculates the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// lcm calculates the least common multiple of two integers
int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

// Main function
const int initialBufSize = 10000; // Initial buffer size for input
const int maxBufSize = 1000000; // Maximum buffer size for input
const int mod = 1e9 + 7; // Modulus value

int main() {
    char* buf = (char*)malloc(initialBufSize * sizeof(char));
    fgets(buf, initialBufSize, stdin);
    char* token = strtok(buf, " ");
    int N = atoi(token);
    token = strtok(NULL, " ");
    int M = atoi(token);
    int tmp = minInt(N, M / 2); // Calculate the minimum of N and half of M
    int ans = 0;
    ans += tmp; // Add the temporary value to the answer
    N -= tmp; // Decrease N by the temporary value
    M -= tmp * 2; // Decrease M by twice the temporary value
    // Output the final answer, which includes the remaining M divided by 4
    printf("%d\n", ans + M / 4);
    return 0;
}

