
#include <stdio.h>
#include <stdlib.h>

// Utility Functions

// Reads the next input as a string
char* nextStr() {
    char* str = (char*)malloc(100 * sizeof(char));
    fgets(str, 100, stdin);
    return str;
}

// Reads the next input as an integer
int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Returns the maximum of two integers
int maxInt(int a, int b) {
    return (a > b)? a : b;
}

// Returns the minimum of two integers
int minInt(int a, int b) {
    return (a < b)? a : b;
}

// Returns the absolute value of an integer
int absInt(int a) {
    return (a >= 0)? a : -a;
}

// Returns the absolute value of a float64
float absFloat64(float a) {
    return (a >= 0)? a : -a;
}

// Returns the maximum of two float64 values
float maxFloat64(float a, float b) {
    return (a > b)? a : b;
}

// Returns the minimum of two float64 values
float minFloat64(float a, float b) {
    return (a > b)? b : a;
}

// Converts a string to an integer
int str2Int(char* s) {
    return atoi(s);
}

// Reverses a string
char* reverse(char* s) {
    int len = strlen(s);
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        reversed[i] = s[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

// Raises an integer to the power of another integer
int powInt(int p, int q) {
    return (int)pow(p, q);
}

// Checks if a number is prime
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
    int i = 3;
    while (i <= rootx) {
        if (x % i == 0) {
            return 0;
        }
        i += 2;
    }
    return 1;
}

// Returns the prime factors of a number
int* PrimeFactors(int n) {
    int* pfs = (int*)malloc(100 * sizeof(int));
    int count = 0;

    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs[count++] = 2;
        n = n / 2;
    }

    // n must be odd at this point. so we can skip one element
    // (note i = i + 2)
    for (int i = 3; i * i <= n; i = i + 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs[count++] = i;
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        pfs[count++] = n;
    }

    return pfs;
}

// Returns the prime factors of a number as a map
int* PrimeFactorsMap(int n) {
    int* pfs = (int*)malloc(100 * sizeof(int));
    int count = 0;

    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs[count++] = 2;
        n = n / 2;
    }

    // n must be odd at this point. so we can skip one element
    // (note i = i + 2)
    for (int i = 3; i * i <= n; i = i + 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs[count++] = i;
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        pfs[count++] = n;
    }

    return pfs;
}

// Sums up a slice of integers
int sumInts(int* x, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += x[i];
    }
    return total;
}

// Computes the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Computes the least common multiple of two integers
int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

// Constants and Variables

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Main Function
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int tmp = minInt(N, M / 2);
    int ans = 0;
    ans += tmp;
    N -= tmp;
    M -= tmp * 2;
    printf("%d\n", ans + M / 4);
    return 0;
}

