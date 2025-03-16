#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int mod = 1000000007;

int max(int a, int b) {
    return (a > b) ? a : b;
}

map<int, int> primeFactorize(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }
    if (n != 1) {
        res[n]++;
    }
    return res;
}

int pow(int n, int k) {
    if (k == 0) return 1;
    else if (k % 2 == 1) return (1LL * pow(n, k - 1) * n) % mod;
    else {
        int t = pow(n, k / 2);
        return (1LL * t * t) % mod;
    }
}

int add(int a, int b) {
    return (a + b) % mod;
}

int sub(int a, int b) {
    return (a + mod - b) % mod;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int div(int a, int b) {
    return mul(a, pow(b, mod - 2));
}

int main() {
    // Initialize variables
    int n;
    cin >> n; // Read the number of integers from the standard input
    vector<int> as(n); // Create a vector to store the input integers
    map<int, int> ps; // Create a map to store the prime factors and their powers

    // Read the input integers and calculate their prime factors
    for (int i = 0; i < n; i++) {
        cin >> as[i]; // Read an integer from the standard input

        map<int, int> ns = primeFactorize(as[i]); // Calculate the prime factors and their powers of the current integer
        for (const auto& [k, v] : ns) { // Iterate through the map to update the powers of the prime factors
            ps[k] = max(ps[k], v); // Update the power of the current prime factor if it's greater
        }
    }

    // Calculate the answer
    int x = 1; // Initialize a variable to store the product of prime factors
    for (const auto& [k, v] : ps) { // Iterate through the map to calculate the product of prime factors
        for (int i = 1; i <= v; i++) { // Calculate the power of the prime factor
            x = mul(x, k); // Multiply the current product with the prime factor
        }
    }

    int ans = 0; // Initialize a variable to store the answer
    for (int i = 0; i < n; i++) { // Iterate through the array to calculate the answer
        ans = add(ans, div(x, as[i])); // Calculate the difference between the current product and the current integer, and add it to the answer
    }

    cout << ans << endl; // Print the answer
    return 0;
}

// <END-OF-CODE>
