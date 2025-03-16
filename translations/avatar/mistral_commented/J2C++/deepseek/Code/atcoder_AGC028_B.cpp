#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

long long modinv(long long a, int m) { // Method to calculate the modular inverse of 'a' with respect to 'm'
    long long b = m;
    long long u = 1;
    long long v = 0;
    long long tmp = 0;

    // Use extended Euclidean algorithm to find the modular inverse
    while (b > 0) {
        long long t = a / b;
        a -= t * b;
        tmp = a;
        a = b;
        b = tmp;
        u -= t * v;
        tmp = u;
        u = v;
        v = tmp;
    }

    u %= m; // If the result is negative, add 'm' to make it positive
    if (u < 0) {
        u += m;
    }

    return u; // Return the modular inverse
}

int main() {
    int n;
    cin >> n; // Read the number of elements in the array
    cin.ignore(); // Ignore the newline character after reading 'n'

    string line;
    getline(cin, line); // Read the array elements as a single line
    stringstream ss(line);
    vector<int> a(n);
    string s;

    // Parse each string element in the array and store it as an integer in 'a' array
    for (int i = 0; i < n; i++) {
        getline(ss, s, ' ');
        a[i] = stoi(s);
    }

    const int mod = 1000000007; // Set the modulus value
    long long p = 1; // Initialize 'p' variable to calculate the factorial of all numbers from 2 to 'n'

    // Calculate the factorial of all numbers from 2 to 'n' and store it in 'p' variable
    for (int i = 2; i <= n; i++) {
        p = p * i % mod;
    }

    vector<long long> q(n); // Initialize a long long array 'q' of size 'n'
    q[0] = 1; // Initialize the first element of 'q' array with 1

    // Calculate the values of 'q' array using the formula (q[i] = q[i-1] + 1/i % mod)
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }

    long long ans = 0; // Initialize the answer variable

    // Calculate the answer using the formula ans = sum of (q[i] * a[i] * p) for all i from 0 to n-1
    for (int i = 0; i < n; i++) {
        long long val = q[i] + q[n - i - 1] - 1; // Calculate the value of 'val' using the formula
        val *= a[i]; // Multiply 'val' with 'a[i]'
        val %= mod; // Modulo the result with the modulus value
        val *= p; // Multiply 'val' with 'p'
        val %= mod; // Modulo the result with the modulus value
        ans += val; // Add the result to the answer
        ans %= mod; // Modulo the answer with the modulus value
    }

    cout << ans << endl; // Print the answer

    return 0;
}
