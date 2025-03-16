
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 998244353;
const int facNum = 300001;

int Pow(int a, int n) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (n & 1) {
            ans = (long long)ans * a % mod; // Multiply by a if n is odd
        }
        a = (long long)a * a % mod; // Square a
        n >>= 1; // Right shift n
    }
    return ans; // Return the result
}

int Gcd(int a, int b) {
    if (a < b) {
        return Gcd(b, a); // Ensure a is greater than b
    }
    while (b!= 0) {
        a %= b; // Apply Euclidean algorithm
        swap(a, b);
    }
    return a; // Return the GCD
}

int min(int a, int b) {
    return a < b? a : b; // Return the minimum of two integers
}

int combination(int n, int k, vector<int>& fac, vector<int>& ifac) {
    if (n < k || n < 0) {
        return 0; // Return 0 if invalid
    }
    if (k == 0) {
        return 1; // Return 1 if k is 0
    }
    // Calculate combination using factorials
    int ans = (long long)ifac[k] * ifac[n - k] % mod;
    return (long long)ans * fac[n] % mod;
}

pair<vector<int>, vector<int>> factorial() {
    vector<int> fac(facNum); // Create a vector for factorials
    fac[0] = 1;
    vector<int> ifac(facNum); // Create a vector for inverse factorials
    ifac[0] = 1;
    for (int i = 1; i < facNum; i++) {
        fac[i] = (long long)fac[i - 1] * i % mod; // Compute factorial
        ifac[i] = Pow(fac[i], mod - 2); // Compute inverse factorial using Fermat's little theorem
    }
    return make_pair(fac, ifac); // Return the factorials and their inverses
}

int lowerBound(vector<int>& vs, int v) {
    int n = vs.size() / 2; // Initialize mid index
    int m = vs.size(); // Length of the vector
    while (m!= n) {
        if (vs[n] < v) {
            n = (m - n + 1) / 2 + n; // Move to the right half
        } else {
            m = n; // Move to the left half
            n = n / 2; // Update mid index
        }
    }
    return n; // Return the found index
}

vector<int> IntSlice(int n, int init) {
    vector<int> r(n); // Create a vector of length n
    for (int i = 0; i < n; i++) {
        r[i] = init; // Initialize each element
    }
    return r; // Return the initialized vector
}

int main() {
    int N;
    cin >> N; // Read an integer N from input
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue; // Skip numbers divisible by 3 or 5
        }
        sum += i; // Add the number to the sum
    }
    cout << sum << endl; // Output the final sum
    return 0;
}

The above C++ code is a translation of the given Go code. It includes the necessary functions and data structures to perform the same calculations and operations as the original Go code. The main function reads an integer N from input, calculates the sum of all integers from 1 to N that are not divisible by 3 or 5, and outputs the final sum.