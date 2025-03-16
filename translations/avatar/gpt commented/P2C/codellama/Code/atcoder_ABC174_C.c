#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Define a constant for modulo operations
const int mod = 1000000007;

// Define a function to read an integer from input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Define a function to read a string from input
char* read_string() {
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Define a function to read a list of integers from input
int* read_int_list() {
    int* list = (int*)malloc(100 * sizeof(int));
    int size = 0;
    char* str = read_string();
    char* token = strtok(str, " ");
    while (token != NULL) {
        list[size++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(str);
    return list;
}

// Define a function to read a list of strings from input
char** read_string_list() {
    char** list = (char**)malloc(100 * sizeof(char*));
    int size = 0;
    char* str = read_string();
    char* token = strtok(str, " ");
    while (token != NULL) {
        list[size++] = token;
        token = strtok(NULL, " ");
    }
    free(str);
    return list;
}

// Define a function to print an integer to output
void print_int(int x) {
    printf("%d\n", x);
}

// Define a function to print a string to output
void print_string(char* str) {
    printf("%s\n", str);
}

// Define a function to print a list of integers to output
void print_int_list(int* list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Define a function to print a list of strings to output
void print_string_list(char** list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", list[i]);
    }
    printf("\n");
}

// Define a function to calculate the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Define a function to calculate the least common multiple of two integers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Define a function to calculate the factorial of an integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Define a function to calculate the binomial coefficient of two integers
int binomial_coefficient(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
}

// Define a function to calculate the Fibonacci number of an integer
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Define a function to calculate the power of an integer
int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    return x * power(x, y - 1);
}

// Define a function to calculate the absolute value of an integer
int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// Define a function to calculate the square root of an integer
int sqrt(int x) {
    if (x == 0) {
        return 0;
    }
    int start = 1;
    int end = x;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

// Define a function to calculate the modulo inverse of an integer
int mod_inverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

// Define a function to calculate the greatest common divisor of two integers using the Euclidean algorithm
int gcd_euclidean(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Define a function to calculate the least common multiple of two integers
int lcm_naive(int a, int b) {
    return a * b / gcd_euclidean(a, b);
}

// Define a function to calculate the greatest common divisor of two integers using the binary GCD algorithm
int gcd_binary(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    int shift = 0;
    while ((a | b) & 1 == 0) {
        a >>= 1;
        b >>= 1;
        shift++;
    }
    while (a != b) {
        while ((a & 1) == 0) {
            a >>= 1;
        }
        while ((b & 1) == 0) {
            b >>= 1;
        }
        if (a > b) {
            int t = b;
            b = a;
            a = t;
        }
        b = b - a;
    }
    return a << shift;
}

// Define a function to calculate the least common multiple of two integers using the binary GCD algorithm
int lcm_binary(int a, int b) {
    return a * b / gcd_binary(a, b);
}

// Define a function to calculate the greatest common divisor of two integers using the Stein's algorithm
int gcd_stein(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    int shift = 0;
    while ((a | b) & 1 == 0) {
        a >>= 1;
        b >>= 1;
        shift++;
    }
    while (a != b) {
        while ((a & 1) == 0) {
            a >>= 1;
        }
        while ((b & 1) == 0) {
            b >>= 1;
        }
        if (a > b) {
            int t = b;
            b = a;
            a = t;
        }
        b = b - a;
    }
    return a << shift;
}

// Define a function to calculate the least common multiple of two integers using the Stein's algorithm
int lcm_stein(int a, int b) {
    return a * b / gcd_stein(a, b);
}

// Define a function to calculate the greatest common divisor of two integers using the binary GCD algorithm
int gcd_binary_stein(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    int shift = 0;
    while ((a | b) & 1 == 0) {
        a >>= 1;
        b >>= 1;
        shift++;
    }
    while (a != b) {
        while ((a & 1) == 0) {
            a >>= 1;
        }
        while ((b & 1) == 0) {
            b >>= 1;
        }
        if (a > b) {
            int t = b;
            b = a;
            a = t;
        }
        b = b - a;
    }
    return a << shift;
}

// Define a function to calculate the least common multiple of two integers using the binary GCD algorithm
int lcm_binary_stein(int a, int b) {
    return a * b / gcd_binary_stein(a, b);
}

// Define a function to calculate the greatest common divisor of two integers using the Euclidean algorithm
int gcd_euclidean_stein(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Define a function to calculate the least common multiple of two integers using the Euclidean algorithm
int lcm_euclidean_stein(int a, int b) {
    return a * b / gcd_euclidean_stein(a, b);
}

// Define a function to calculate the greatest common divisor of two integers using the Euclidean algorithm
int gcd_euclidean_stein_mod(int a, int b, int m) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Define a function to calculate the least common multiple of two integers using the Euclidean algorithm
int lcm_euclidean_stein_mod(int a, int b, int m) {
    return a * b / gcd_euclidean_stein_mod(a, b, m);
}

// Define a function to calculate the greatest common divisor of two integers using the Euclidean algorithm
int gcd_euclidean_stein_mod_recursive(int a, int b, int m) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return gcd_euclidean_stein_mod_recursive(b, a % b, m);
}

// Define a function to calculate the least common multiple of two integers using the Euclidean algorithm
int lcm_euclidean_stein_mod_recursive(int a, int b, int m) {
    return a * b / gcd_euclidean_stein_mod_recursive(a, b, m);
}

// Define a function to calculate the greatest common divisor of two integers using the Euclidean algorithm
int gcd_euclidean_stein_mod_recursive_optimized(int a, int b, int m) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a < b) {
        return gcd_euclidean_stein_mod_recursive_optimized(b % a, a, m);
    }
    return gcd_euclidean_stein_mod_recursive_optimized(b, a % b, m);
}

// Define a function to calculate the least common multiple of two integers using the Euclidean algorithm
int lcm_euclidean_stein_mod_recursive_optimized(int a, int b, int m) {
    return a * b / gcd_euclidean_stein_mod_recursive_optimized(a, b, m);
}

// Define a function to calculate the greatest common divisor of two integers using the Euclidean algorithm
int gcd_euclidean_stein_mod_recursive_optimized_2(int a, int b, int m) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a < b) {
        return gcd_euclidean_stein_mod_recursive_optimized_2(b % a, a, m);
    }
    if (a % 2 == 0 && b % 2 == 0) {
        return 2 * gcd_euclidean_stein_mod_recursive_optimized_2(a / 2, b / 2, m);
    }
    if (a % 2 == 0) {
        return gcd_euclidean_stein_mod_recursive_optimized_2(a / 2, b, m);
    }
    if (b % 2 == 0) {
        return gcd_euclidean_stein_mod_recursive_optimized_2(a, b / 2, m);
    }
    return gcd_euclidean_stein_mod_recursive_optimized_2(a, b, m);
}

// Define a function to calculate the least common multiple of two integers using the Euclidean algorithm
int lcm_euclidean_stein_mod_recursive_optimized_2(int a, int b, int