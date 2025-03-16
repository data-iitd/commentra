#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
string nextStr() {
    string s;
    cin >> s;
    return s;
}

// nextInt reads the next integer from input
int nextInt() {
    int i;
    cin >> i;
    return i;
}

// maxInt returns the maximum of two integers
int maxInt(int a, int b) {
    return a > b ? a : b;
}

// minInt returns the minimum of two integers
int minInt(int a, int b) {
    return a < b ? a : b;
}

// absInt returns the absolute value of an integer
int absInt(int a) {
    return a >= 0 ? a : -a;
}

// absFloat64 returns the absolute value of a float64
double absFloat64(double a) {
    return a >= 0 ? a : -a;
}

// maxFloat64 returns the maximum of two float64 values
double maxFloat64(double a, double b) {
    return a > b ? a : b;
}

// minFloat64 returns the minimum of two float64 values
double minFloat64(double a, double b) {
    return a < b ? a : b;
}

// str2Int converts a string to an integer
int str2Int(string s) {
    return stoi(s);
}

// reverse returns the reversed string
string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// powInt calculates p raised to the power of q
int powInt(int p, int q) {
    return pow(p, q);
}

// isPrime checks if a number is prime
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

// PrimeFactors returns the prime factors of a number
vector<int> PrimeFactors(int n) {
    vector<int> pfs;
    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs.push_back(2);
        n = n / 2;
    }

    // n must be odd at this point, so we can skip one element
    for (int i = 3; i * i <= n; i += 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs.push_back(i);
            n = n / i;
        }
    }

    // Handle the case when n is a prime number greater than 2
    if (n > 2) {
        pfs.push_back(n);
    }

    return pfs;
}

// PrimeFactorsMap returns a map of prime factors and their counts
unordered_map<int, int> PrimeFactorsMap(int n) {
    unordered_map<int, int> pfs;
    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs[2]++;
        n = n / 2;
    }

    // n must be odd at this point, so we can skip one element
    for (int i = 3; i * i <= n; i += 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs[i]++;
            n = n / i;
        }
    }

    // Handle the case when n is a prime number greater than 2
    if (n > 2) {
        pfs[n]++;
    }

    return pfs;
}

// sumInts returns the sum of a vector of integers
int sumInts(vector<int> x) {
    int total = 0;
    for (int v : x) {
        total += v;
    }
    return total;
}

// gcd calculates the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// lcm calculates the least common multiple of two integers
int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

// Main function
int main() {
    // Read the number of 'S' and 'c'
    int N = nextInt();
    int M = nextInt();
    int tmp = minInt(N, M / 2); // Calculate the minimum of N and half of M
    int ans = 0;
    ans += tmp; // Add the temporary value to the answer
    N -= tmp; // Decrease N by the temporary value
    M -= tmp * 2; // Decrease M by twice the temporary value
    // Output the final answer, which includes the remaining M divided by 4
    cout << ans + M / 4 << endl;
    return 0;
}

