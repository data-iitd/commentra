#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <queue>

using namespace std;

// Constants for modulo value
const int mod = 1e9 + 7;

// Function to read an integer from input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
    return static_cast<int>(pow(static_cast<double>(p), static_cast<double>(q)));
}

// Function to calculate n raised to the power of p modulo mod
int powMod(int n, int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (1LL * t * t) % mod;
    } else {
        return (1LL * n * powMod(n, p - 1)) % mod;
    }
}

// Function to find the minimum value among a list of integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Function to find the maximum value among a list of integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = static_cast<int>(sqrt(n));
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to calculate the greatest common divisor (GCD) of two integers
int calcGcd(int x, int y) {
    return y == 0 ? x : calcGcd(y, x % y);
}

// Function to get all divisors of a number
vector<int> getDivisor(int n) {
    unordered_set<int> divisor;
    divisor.insert(1);
    if (n != 1) divisor.insert(n);

    int sqrtN = static_cast<int>(sqrt(n));
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }

    return vector<int>(divisor.begin(), divisor.end());
}

// Main function
int main() {
    // Read an integer input
    int N = getInt();

    // Determine the output based on the last digit of N
    switch (N % 10) {
        case 2: case 4: case 5: case 7: case 9:
            cout << "hon" << endl;
            break;
        case 0: case 1: case 6: case 8:
            cout << "pon" << endl;
            break;
        case 3:
            cout << "bon" << endl;
            break;
    }

    return 0;
}

// <END-OF-CODE>
