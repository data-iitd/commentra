#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Constants
const int mod = 998244353;
const int facNum = 300001;

// Function to read an integer from standard input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to calculate a^n modulo mod
int Pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (1LL * ans * a) % mod;
        }
        a = (1LL * a * a) % mod;
        n >>= 1;
    }
    return ans;
}

// Function to calculate the greatest common divisor of a and b
int Gcd(int a, int b) {
    if (a < b) return Gcd(b, a);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the binomial coefficient (n choose k) modulo mod
int combination(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < k || n < 0) return 0;
    if (k == 0) return 1;
    return (1LL * ifac[k] * ifac[n - k] % mod) * fac[n] % mod;
}

// Function to calculate factorials and their modular inverses
pair<vector<int>, vector<int>> factorial() {
    vector<int> fac(facNum), ifac(facNum);
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < facNum; i++) {
        fac[i] = (1LL * fac[i - 1] * i) % mod;
        ifac[i] = (1LL * ifac[i - 1] * Pow(i, mod - 2)) % mod;
    }
    return {fac, ifac};
}

// Main function
int main() {
    // Read an integer N from the standard input
    int N = readInt();

    // Initialize a variable sum to 0
    int sum = 0;

    // Loop through numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        // If the number is not divisible by 3 or 5, add it to the sum
        if (i % 3 != 0 && i % 5 != 0) {
            sum += i;
        }
    }

    // Print the result to the standard output
    cout << sum << endl;

    return 0;
}

// <END-OF-CODE>
