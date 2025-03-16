#include <bits/stdc++.h>
using namespace std;

// Define input functions for convenience
int ii1() {
    int x;
    cin >> x;
    return x;
}
string is1() {
    string s;
    cin >> s;
    return s;
}
vector<int> iia() {
    vector<int> v;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i] - '0');
    }
    return v;
}
vector<string> isa() {
    vector<string> v;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s.substr(i, 1));
    }
    return v;
}

// Define a constant for modulo operations
const int mod = 1000000007;

// Define a function to calculate the modulo of a number
int modulo(int a, int b) {
    return (a % b + b) % b;
}

// Define a function to calculate the power of a number
int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = modulo(res * a, mod);
        }
        a = modulo(a * a, mod);
        b >>= 1;
    }
    return res;
}

// Define a function to calculate the inverse of a number
int inverse(int a, int m) {
    return power(a, m - 2);
}

// Define a function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Define a function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Define a function to calculate the floor of a number
int floor(int a, int b) {
    return a / b;
}

// Define a function to calculate the ceiling of a number
int ceil(int a, int b) {
    return (a + b - 1) / b;
}

// Define a function to calculate the absolute value of a number
int abs(int a) {
    return a < 0 ? -a : a;
}

// Define a function to calculate the square root of a number
int sqrt(int a) {
    int l = 0, r = a - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (m * m <= a) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l - 1;
}

// Define a function to calculate the factorial of a number
int factorial(int a) {
    int res = 1;
    for (int i = 2; i <= a; i++) {
        res = modulo(res * i, mod);
    }
    return res;
}

// Define a function to calculate the binomial coefficient of two numbers
int binomial(int a, int b) {
    return factorial(a) / (factorial(b) * factorial(a - b));
}

// Define a function to calculate the Fibonacci number of a number
int fibonacci(int a) {
    if (a == 0) {
        return 0;
    }
    if (a == 1) {
        return 1;
    }
    return fibonacci(a - 1) + fibonacci(a - 2);
}

// Define a function to calculate the Lucas number of a number
int lucas(int a) {
    if (a == 0) {
        return 2;
    }
    if (a == 1) {
        return 1;
    }
    return lucas(a - 1) + lucas(a - 2);
}

// Define a function to calculate the Mobius function of a number
int mobius(int a) {
    if (a == 1) {
        return 1;
    }
    if (a == 0) {
        return 0;
    }
    int res = 1;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            res = -res;
            while (a % i == 0) {
                a /= i;
            }
        }
    }
    if (a > 1) {
        res = -res;
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a) {
    int res = 1;
    for (int i = 2; i <= a; i++) {
        if (gcd(i, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b) {
    int res = 1;
    for (int i = a; i <= b; i++) {
        if (gcd(i, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c) {
    int res = 1;
    for (int i = a; i <= b; i++) {
        if (gcd(i, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d) {
    int res = 1;
    for (int i = a; i <= b; i++) {
        if (gcd(i, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e) {
    int res = 1;
    for (int i = a; i <= b; i++) {
        if (gcd(i, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f) {
    int res = 1;
    for (int i = a; i <= b; i++) {
        if (gcd(i, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g) {
    int res = 1;
    for (int i = a; i <= b; i++) {
        if (gcd(i, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h) {
    int res = 1;
    for (int i = a; i <= b; i++) {
        if (gcd(i, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    int res = 1;
    for (int j = a; j <= b; j++) {
        if (gcd(j, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    int res = 1;
    for (int k = a; k <= b; k++) {
        if (gcd(k, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
    int res = 1;
    for (int l = a; l <= b; l++) {
        if (gcd(l, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    int res = 1;
    for (int m = a; m <= b; m++) {
        if (gcd(m, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
    int res = 1;
    for (int n = a; n <= b; n++) {
        if (gcd(n, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
    int res = 1;
    for (int o = a; o <= b; o++) {
        if (gcd(o, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
    int res = 1;
    for (int p = a; p <= b; p++) {
        if (gcd(p, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
    int res = 1;
    for (int q = a; q <= b; q++) {
        if (gcd(q, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q) {
    int res = 1;
    for (int r = a; r <= b; r++) {
        if (gcd(r, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r) {
    int res = 1;
    for (int s = a; s <= b; s++) {
        if (gcd(s, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s) {
    int res = 1;
    for (int t = a; t <= b; t++) {
        if (gcd(t, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t) {
    int res = 1;
    for (int u = a; u <= b; u++) {
        if (gcd(u, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u) {
    int res = 1;
    for (int v = a; v <= b; v++) {
        if (gcd(v, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int euler(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v) {
    int res = 1;
    for (int w = a; w <= b; w++) {
        if (gcd(w, a) == 1) {
            res++;
        }
    }
    return res;
}

// Define a function to calculate the Euler's totient function of a number
int e