#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007 // Define constant for modulo arithmetic
#define Int long long // Define long integer type

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false; // 2 is the smallest prime number
    else if (num == 2) return true; // 2 is a prime number
    else if (num % 2 == 0) return false; // Even numbers greater than 2 are not prime

    double sqrtNum = sqrt(num); // Calculate square root of number
    for (int i = 3; i <= sqrtNum; i += 2) { // Iterate through odd numbers up to square root
        if (num % i == 0) { // If number is divisible by current odd number
            return false; // It's not a prime number
        }
    }

    // If number is not divisible by any odd number up to its square root, it's a prime number
    return true;
}

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a; // Recursive function to find greatest common divisor
}

Int lcm(Int a, Int b) {
    return a / gcd(a, b) * b; // Find least common multiple by multiplying greatest common divisor and smaller number
}

int Max(int a, int b, int c) {
    int temp = a > b ? a : b; // Find maximum of two numbers
    return temp > c ? temp : c; // Compare maximum with third number and return the result
}

int Min(int a, int b, int c) {
    int temp = a < b ? a : b; // Find minimum of two numbers
    return temp < c ? temp : c; // Compare minimum with third number and return the result
}

bool integer(double num) {
    return floor(num) == num; // Check if a number is an integer
}

Int fact(int num) {
    if (num == 0) // Base case: factorial of 0 is 1
        return 1;
    else
        return num * fact(num - 1); // Recursive call to calculate factorial
}

Int yakusu(int n) {
    int cnt = 0; // Initialize divisor count
    for (int i = 1; i * i <= n; i++) { // Iterate through divisors up to square root of n
        if (n % i == 0) { // If n is divisible by current divisor
            cnt++; // Increment divisor count
            if (i * i != n) cnt++; // If n has more than one divisor, increment count
        }
    }
    return cnt; // Return divisor count
}

Int fact_mod(Int n, Int mod) {
    Int f = 1; // Initialize factorial to 1
    for (Int i = 2; i <= n; i++) f = f * (i % MOD) % MOD; // Calculate factorial modulo m
    return f; // Return the result
}

// Function to calculate x^n modulo m using repeated squaring method
Int mod_pow(Int x, Int n, Int mod) {
    Int res = 1; // Initialize result to 1
    while(n > 0) { // While n is not zero
        if(n & 1) res = (res * x) % mod; // If n is odd, multiply x with result and reduce modulo m
        x = (x * x) % mod; // Square x and reduce modulo m
        n >>= 1; // Divide n by 2
    }
    return res; // Return the final result
}

// Function to calculate the number of combinations of n items taken r at a time modulo m
Int combination_mod(Int n, Int r, Int mod) {
    if(r > n-r) r = n-r; // Adjust r if it's greater than the difference between n and r
    if(r == 0) return 1; // Base case: combination of 0 items is 1
    Int a = 1; // Initialize first term
    for (Int i = 0; i < r; i++) a = a * ((n-i) % MOD) % MOD; // Calculate first term
    Int b = mod_pow(fact_mod(r, mod), mod-2, mod); // Calculate second term
    return (a % MOD) * (b % MOD) % MOD; // Multiply terms and reduce modulo m
}

bool rev(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    return strcmp(s, s) == 0; // Check if original string is equal to its reversed version
}

int main() {
    Int k, a, b; // Initialize variables a, b, and k
    scanf("%lld %lld %lld", &k, &a, &b); // Read input values for k, a, and b

    // Check if there exists an integer between a and b that is divisible by k
    for (Int i = a; i <= b; ++i) {
        if(i % k == 0) { // If current number is divisible by k
            printf("OK\n"); // Print "OK" and exit the program
            return 0; // Exit the program with success status
        }
    }

    printf("NG\n"); // If no number between a and b is divisible by k, print "NG"

    return 0; // Exit the program
}

// <END-OF-CODE>
