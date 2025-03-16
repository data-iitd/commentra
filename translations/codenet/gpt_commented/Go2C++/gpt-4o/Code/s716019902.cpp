#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Define constants for modulo operation and factorial limit
const int mod = 998244353;
const int facNum = 300001;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to calculate a^n under modulo
int Pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (1LL * ans * a) % mod; // Multiply by a if n is odd
        }
        a = (1LL * a * a) % mod; // Square a
        n >>= 1; // Right shift n
    }
    return ans; // Return the result
}

// Function to calculate the greatest common divisor of a and b
int Gcd(int a, int b) {
    if (a < b) {
        swap(a, b); // Ensure a is greater than b
    }
    while (b != 0) {
        int temp = b;
        b = a % b; // Apply Euclidean algorithm
        a = temp;
    }
    return a; // Return the GCD
}

// Function to calculate n choose k using precomputed factorials
int combination(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < k || n < 0) {
        return 0; // Return 0 if invalid
    }
    if (k == 0) {
        return 1; // Return 1 if k is 0
    }
    // Calculate combination using factorials
    return (1LL * ifac[k] * ifac[n - k] % mod) * fac[n] % mod;
}

// Function to precompute factorials and their modular inverses
void factorial(vector<int>& fac, vector<int>& ifac) {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < facNum; i++) {
        fac[i] = (1LL * fac[i - 1] * i) % mod; // Compute factorial
        ifac[i] = (1LL * ifac[i - 1] * Pow(i, mod - 2)) % mod; // Compute inverse factorial using Fermat's little theorem
    }
}

// Function to find the index of the first element in a sorted vector that is not less than v
int lowerBound(const vector<int>& vs, int v) {
    int n = vs.size() / 2; // Initialize mid index
    int m = vs.size(); // Length of the vector
    while (m != n) {
        if (vs[n] < v) {
            n = (m - n + 1) / 2 + n; // Move to the right half
        } else {
            m = n; // Move to the left half
            n /= 2; // Update mid index
        }
    }
    return n; // Return the found index
}

// Function to create a vector of integers initialized to a specific value
vector<int> IntSlice(int n, int init) {
    vector<int> r(n, init); // Create a vector of length n
    return r; // Return the initialized vector
}

int main() {
    // Read an integer N from input
    int N = readInt();
    int sum = 0;

    // Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue; // Skip numbers divisible by 3 or 5
        }
        sum += i; // Add the number to the sum
    }

    // Output the final sum
    cout << sum << endl;

    return 0;
}

// <END-OF-CODE>
