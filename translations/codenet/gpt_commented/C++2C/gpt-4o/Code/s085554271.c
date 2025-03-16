#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

<<<<<<< HEAD
=======
#define MOD 1000000007

>>>>>>> 98c87cb78a (data updated)
// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false; // Numbers less than 2 are not prime
    else if (num == 2) return true; // 2 is prime
    else if (num % 2 == 0) return false; // Exclude even numbers

<<<<<<< HEAD
    int sqrtNum = (int)sqrt(num); // Calculate square root for optimization
=======
    double sqrtNum = sqrt(num); // Calculate square root for optimization
>>>>>>> 98c87cb78a (data updated)
    for (int i = 3; i <= sqrtNum; i += 2) { // Check for factors from 3 to sqrt(num)
        if (num % i == 0) {
            return false; // Not a prime number
        }
    }

    return true; // Number is prime
}

// Function to calculate the greatest common divisor (GCD)
long long gcd(long long a, long long b) {
    return b != 0 ? gcd(b, a % b) : a; // Recursive GCD calculation
}

// Function to calculate the least common multiple (LCM)
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b; // LCM using GCD
}

// Function to find the maximum of three integers
int Max(int a, int b, int c) {
    int temp = a > b ? a : b;
    return temp > c ? temp : c; // Return the maximum value
}

// Function to find the minimum of three integers
int Min(int a, int b, int c) {
    int temp = a < b ? a : b;
    return temp < c ? temp : c; // Return the minimum value
}

// Function to check if a double is an integer
bool integer(double num) {
    return floor(num) == num; // Check if the number is an integer
}

// Recursive function to calculate factorial
long long fact(int num) {
    if (num == 0)
        return 1; // Base case for factorial
    else
        return num * fact(num - 1); // Recursive case
}

// Function to count the number of divisors of n
long long yakusu(int n) {
    int cnt = 0; // Counter for divisors
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++; // Count the divisor
            if (i * i != n) cnt++; // Count the complementary divisor if it's different
        }
    }
    return cnt; // Return the count of divisors
}

// Function to calculate factorial modulo a given number
long long fact_mod(long long n, long long mod) {
    long long f = 1; 
<<<<<<< HEAD
    for (long long i = 2; i <= n; i++) f = f * (i % mod) % mod; // Calculate factorial with modulo
=======
    for (long long i = 2; i <= n; i++) f = f * (i % MOD) % MOD; // Calculate factorial with modulo
>>>>>>> 98c87cb78a (data updated)
    return f; // Return the result
}

// Function to perform modular exponentiation
long long mod_pow(long long x, long long n, long long mod) {
    long long res = 1; // Initialize result
    while(n > 0) {
        if(n & 1) res = (res * x) % mod; // If n is odd, multiply x with result
        x = (x * x) % mod; // Square x
        n >>= 1; // Divide n by 2
    }
    return res; // Return the result
}

// Function to calculate combinations nCr modulo a given number
long long combination_mod(long long n, long long r, long long mod) {
    if(r > n - r) r = n - r; // Use symmetry property of combinations
    if(r == 0) return 1; // Base case for combinations
    long long a = 1; 
    for (long long i = 0; i < r; i++) a = a * ((n - i) % mod) % mod; // Calculate numerator
    long long b = mod_pow(fact_mod(r, mod), mod - 2, mod); // Calculate denominator using Fermat's Little Theorem
    return (a % mod) * (b % mod) % mod; // Return the result
}

// Function to check if a string is a palindrome
bool rev(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return false; // Check if the original string is equal to the reversed string
    }
    return true;
}

// Main function
int main() {
    long long a, b, k; // Declare variables
    scanf("%lld %lld %lld", &k, &a, &b); // Input values for k, a, and b

    // Check for multiples of k in the range [a, b]
    for (long long i = a; i <= b; ++i) {
        if (i % k == 0) {
            printf("OK\n"); // Output OK if a multiple is found
            return 0; // Exit the program
        }
    }
    printf("NG\n"); // Output NG if no multiples are found

    return 0; // Return success
}

/*
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/

