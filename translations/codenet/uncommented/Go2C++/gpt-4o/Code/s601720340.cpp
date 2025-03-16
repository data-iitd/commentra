#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int magic = 1000000007;

int N;
vector<int> p(200000);

int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int X;
    cin >> X;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) {
            cout << X - i << endl;
            exit(0);
        }
        if (find(X + i) == 1) {
            cout << X + i << endl;
            exit(0);
        }
    }
}

int main(int argc, char *argv[]) {
    // CPU and memory profiling can be added here if needed

    solve();

    return 0;
}

// Libraries

// Function to calculate combination
int combination(int n, int m) {
    if (m > n) {
        return 0;
    } else if (m == n || m == 0) {
        return 1;
    } else {
        int res = 1;
        for (int i = 0; i < m; i++) {
            res *= (n - i);
        }
        for (int i = 1; i <= m; i++) {
            res /= i;
        }
        return res;
    }
}

// Calculate combination modulo based on Lucas theorem
int lucas(int n, int m, int p) {
    int ntemp = n;
    int mtemp = m;
    int res = 1;
    for (int i = 0; i < 100; i++) {
        int nreminder = ntemp % p;
        ntemp = ntemp / p;
        int mreminder = mtemp % p;
        mtemp = mtemp / p;
        res = res * (combination(nreminder, mreminder) % p);
        if (ntemp == 0) {
            break;
        }
    }
    return res % p;
}

int combMod(int n, int m, int p) {
    return lucas(n, m, p);
}

// GCD function
int gcd(int a, int b) {
    while (a != 0) {
        a = b % a;
        swap(a, b);
    }
    return b;
}

// Power function
int power2mod(int n, int mod) {
    int res = 1, x = 2;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int power2(int n) {
    return power2mod(n, magic);
}

// <END-OF-CODE>
