#include <stdio.h>
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> 98c87cb78a (data updated)
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007
<<<<<<< HEAD
#define Int long long
=======

long long gcd(long long a, long long b) {
    return b != 0 ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
>>>>>>> 98c87cb78a (data updated)

bool isPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // Exclude even numbers

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
<<<<<<< HEAD
            return false; // Not prime
        }
    }
    return true; // Is prime
}

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

Int lcm(Int a, Int b) {
    return a / gcd(a, b) * b; // Avoid overflow with a*b
}

int Max(int a, int b, int c) {
    int temp = a > b ? a : b;
    return temp > c ? temp : c;
}

int Min(int a, int b, int c) {
    int temp = a < b ? a : b;
    return temp < c ? temp : c;
}

bool integer(double num) {
    return floor(num) == num;
}

Int fact(int num) {
=======
            return false; // Not a prime number
        }
    }
    return true; // Is a prime number
}

long long fact(int num) {
>>>>>>> 98c87cb78a (data updated)
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}

<<<<<<< HEAD
Int yakusu(int n) {
=======
long long yakusu(int n) {
>>>>>>> 98c87cb78a (data updated)
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}

<<<<<<< HEAD
Int fact_mod(Int n, Int mod) {
    Int f = 1;
    for (Int i = 2; i <= n; i++) {
=======
long long fact_mod(long long n, long long mod) {
    long long f = 1;
    for (long long i = 2; i <= n; i++) {
>>>>>>> 98c87cb78a (data updated)
        f = f * (i % MOD) % MOD;
    }
    return f;
}

<<<<<<< HEAD
Int mod_pow(Int x, Int n, Int mod) {
    Int res = 1;
=======
long long mod_pow(long long x, long long n, long long mod) {
    long long res = 1;
>>>>>>> 98c87cb78a (data updated)
    while (n > 0) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

<<<<<<< HEAD
Int combination_mod(Int n, Int r, Int mod) {
    if (r > n - r) r = n - r;
    if (r == 0) return 1;
    Int a = 1;
    for (Int i = 0; i < r; i++) {
        a = a * ((n - i) % mod) % mod;
    }
    Int b = mod_pow(fact_mod(r, mod), mod - 2, mod);
=======
long long combination_mod(long long n, long long r, long long mod) {
    if (r > n - r) r = n - r;
    if (r == 0) return 1;
    long long a = 1;
    for (long long i = 0; i < r; i++) {
        a = a * ((n - i) % mod) % mod;
    }
    long long b = mod_pow(fact_mod(r, mod), mod - 2, mod);
>>>>>>> 98c87cb78a (data updated)
    return (a % mod) * (b % mod) % mod;
}

bool rev(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
<<<<<<< HEAD
    Int a, b, k;
    scanf("%lld %lld %lld", &k, &a, &b);
    for (Int i = a; i <= b; ++i) {
=======
    long long a, b, k;
    scanf("%lld %lld %lld", &k, &a, &b);
    for (long long i = a; i <= b; ++i) {
>>>>>>> 98c87cb78a (data updated)
        if (i % k == 0) {
            printf("OK\n");
            return 0;
        }
    }
    printf("NG\n");
    return 0;
}

/* <END-OF-CODE> */
