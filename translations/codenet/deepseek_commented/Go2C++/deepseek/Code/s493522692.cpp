#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <sstream>
#include <queue>

using namespace std;

// Utility Functions

// Reads the next input as a string
string nextStr() {
    string s;
    cin >> s;
    return s;
}

// Reads the next input as an integer
int nextInt() {
    int i;
    cin >> i;
    return i;
}

// Returns the maximum of two integers
int maxInt(int a, int b) {
    return a > b ? a : b;
}

// Returns the minimum of two integers
int minInt(int a, int b) {
    return a < b ? a : b;
}

// Returns the absolute value of an integer
int absInt(int a) {
    return a >= 0 ? a : -a;
}

// Returns the absolute value of a float64
double absFloat64(double a) {
    return a >= 0 ? a : -a;
}

// Returns the maximum of two float64 values
double maxFloat64(double a, double b) {
    return a > b ? a : b;
}

// Returns the minimum of two float64 values
double minFloat64(double a, double b) {
    return a < b ? a : b;
}

// Converts a string to an integer
int str2Int(string s) {
    return stoi(s);
}

// Reverses a string
string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// Raises an integer to the power of another integer
int powInt(int p, int q) {
    return pow(p, q);
}

// Checks if a number is prime
bool isPrime(int x) {
    if (x == 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    bool b = true;
    int rootx = sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            b = false;
            break;
        }
    }
    return b;
}

// Returns the prime factors of a number
vector<int> PrimeFactors(int n) {
    vector<int> pfs;
    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs.push_back(2);
        n = n / 2;
    }

    // n must be odd at this point. so we can skip one element
    // (note i = i + 2)
    for (int i = 3; i * i <= n; i += 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs.push_back(i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        pfs.push_back(n);
    }

    return pfs;
}

// Returns the prime factors of a number as a map
unordered_map<int, int> PrimeFactorsMap(int n) {
    unordered_map<int, int> pfs;
    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs[2]++;
        n = n / 2;
    }

    // n must be odd at this point. so we can skip one element
    // (note i = i + 2)
    for (int i = 3; i * i <= n; i += 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs[i]++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        pfs[n]++;
    }

    return pfs;
}

// Sums up a vector of integers
int sumInts(vector<int>& x) {
    int total = 0;
    for (int v : x) {
        total += v;
    }
    return total;
}

// Computes the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Computes the least common multiple of two integers
int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

// Constants and Variables

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const double mod = 1e9 + 7;

// Main Function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 'S'がN個、'c'がM個
    int N = nextInt();
    int M = nextInt();
    int tmp = minInt(N, M / 2);
    int ans = 0;
    ans += tmp;
    N -= tmp;
    M -= tmp * 2;
    //cout << ans << " " << N << " " << M << endl;
    cout << ans + M / 4 << endl;

    return 0;
}
